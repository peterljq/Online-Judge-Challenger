

/*
 【题意分析】
 有一4x4棋盘，上面有16枚双面棋子（一面为黑，一面为白），
 当翻动一只棋子时，该棋子上下左右相邻的棋子也会同时翻面。
 以b代表黑面，w代表白面，给出一个棋盘状态，
 问从该棋盘状态开始，使棋盘变成全黑或全白，至少需要翻转多少步
 【解题思路】
 此题有多种解法，枚举、搜索（BFS、DFS）均可。
 搜索的方法网上已有很多人给出（我本人几年前也给过2种搜索代码），
 这里补充一下枚举的思路。
 ========================================
 首先需要等价变换一下问题，题目需要求的是棋盘从某状态到达全黑/全白的最小翻转步数，
 可等价变成棋盘从全黑/全白状态开始，到达指定状态的最小翻转步数，更便于处理
 为了简化问题，这里进一步把问题简化为【棋盘从全黑状态开始，到达指定状态的最小翻转步数】
 只要求到全黑的答案，全白的答案是可以直接推导的，这个后面再说。
 那么枚举的思路就很简单了：
 ① 预先打表计算出【棋盘从全黑状态开始，到达所有不重复状态的最小翻转步数】
 ② 任意给定一个状态，查表有这个状态，则直接输出步数；否则输出不可达
 ========================================
 为了便于记录棋盘状态，这里使用二进制数对棋盘状态进行压缩，具体方法如下：
 对棋盘矩阵进行编码：
 * * * *      从左到右分别为第 0, 1, 2, 3位
 % % % %      从左到右分别为第 4, 5, 6, 7位
 # # # #      从左到右分别为第 8, 9,10,11位
 @ @ @ @      从左到右分别为第12,13,14,15位
 由于棋盘每一格只有黑白两种状态，可用0、1进行表示，由此可转换成二进制数：
 @@@@ #### %%%% ****
 15      ←         0
 最终可以用一个 unsigned int 数（共32位，这里使用低16位）存储整个棋盘状态，
 令 黑=0，白=1：
 ① 当翻转某一位上的棋子时，相当于使该位与 二进制1 做异或运算.
 ② 棋盘处于全黑状态时，unsigned int 的低16位值为 0x0000
 ③ 棋盘处于全白状态时，unsigned int 的低16位值为 0xFFFF
 ========================================
 另一方面，不难可以看出每格棋子最多只可以翻转1次，
 这是因为只要其中一格重复翻了2次(不论是连续翻动还是不连翻动)，
 那么它以及周边的棋子和没翻动时的状态是一致的，
 由此就可以确定这个4x4棋盘【理论上最多只能翻16次，共2^16 = 65536 种状态】
 为了记录翻转过的棋子，可以把 unsigned int 数的高16位也利用起来，
 令高16位为棋盘操作位，从全0（全黑）状态开始，翻动过的棋子位置标记为1，没翻动过的标记为0
 这样我们就可以通过充分利用一个  unsigned int 数的32位，
 记录棋盘在处于某个状态时的编码，包括翻转过的棋子位置、以及当前棋子的翻转情况。
 
 ========================================
 确定了棋盘状态的记录方式，就可以开始枚举所有棋盘状态了。
 首先理解几个前提条件：
 ① 棋盘初始状态为全0（暂不考虑全1）
 ② 一次只能翻转一个棋子，不能重复翻转同一个棋子（因为会还原状态，无意义）
 ③ 最多只能翻转 4x4 = 16 次
 ④ 第 n 次的翻转操作是基于 第 n-1 次的所有可能的棋盘状态
 ⑤ 可能存在不同的翻转次数，会得到相同的棋盘状态
 根据①②③④，这里可以使用BFS的思想:
 从初始状态开始，分别记录16步（类比16层的树）翻转操作中每一步的所有棋盘状态。
 而④⑤可以用来指导BFS过程的剪枝，用于加速搜索：
 若第 i、j 步的（i<=j）翻转操作均出现了状态A，那么第j步的状态A舍弃，
 这是因为从第j步的状态A又会引申出大量重复状态，且步长必定比第i步长。
 ========================================
 上述解题方法是针对初始状态为全0（全黑）情况下的，
 那么初始状态为全1（全白）需要重新计算一次所有状态么？
 不需要，其实很简单。
 当已经计算出初始状态为全0时、在16步内可到达的所有棋盘状态后，
 对于给定某个棋盘状态，只要对该棋盘状态取反（黑变白、白变黑），
 那么【取反后的棋盘状态到达全0需要的最小步数】等价于【原棋盘状态到达全1需要的最小步数】
 注意这里有个误区：
 【不能】先计算原棋盘状态到达全0需要的最小步数，再用16减去之
 全0与全1导向的结果集并不是减法意义上的互补
 事实上，把BFS搜索到的全状态列印出来可以发现：
 ① 重复状态多达61440种，有效状态只有4096种
 ② 有效状态在第8步之前就可全部找到（准确而言是0-7步），且不是呈对称分布
 ③ 从全0到全1只需经过4步翻转
 ④ 这种结果分布主要是受翻棋时所影响的棋子范围所决定的
 */


#include <set>
#include <iostream>
using namespace std;

// 无符号整型(32位)，用于记录棋盘编码，主要为了避免int32的负数影响
// 初始棋盘状态为全0（全黑）
// 高16位为棋盘操作位，翻动过的棋子位置标记为1
// 低16位为棋盘状态位, 记录当前棋盘状态（白朝上为1，黑朝上为0）
typedef unsigned int _UINT;


const static int MAX_STEP = 16;            // 可翻棋的最大步数
const static int MAX_STATUS = 65536;    // 总状态数 = 2^16（含重复数）


// 棋盘状态掩码：当翻转位置i的棋子时,STATUS_MASKS[i]为所有受影响的相邻位置
// 位置i：在4x4棋盘内，从左到右、从上到下按0-15依次编码
const static _UINT STATUS_MASKS[MAX_STEP] = {
    0x00000013, 0x00000027, 0x0000004E, 0x0000008C,
    0x00000131, 0x00000272, 0x000004E4, 0x000008C8,
    0x00001310, 0x00002720, 0x00004E40, 0x00008C80,
    0x00003100, 0x00007200, 0x0000E400, 0x0000C800
};


/**
 * 棋盘对象
 */
class Chess {
public:
    Chess();
    ~Chess();
    int getStep(int status);    // 计算从全0或全1状态到达指定棋盘状态的最小步数
    
private:
    void bfsAllStatus(void);            // 记录不重复地翻动1-16步可得到的所有棋盘状态
    _UINT filp(_UINT chess, int bitPos);// 翻动棋盘上某个指定位位置的棋子
    
    int toStatus(_UINT chess);        // 从棋盘编码提取棋盘状态信息
    int getMaxBitPos(_UINT chess);    // 从棋盘编码提取棋盘操作信息，获得其中最大翻转编号的位置
    int getFilpCount(_UINT chess);    // 从棋盘编码提取棋盘操作信息，获取棋盘从全0状态开始共被翻动棋子的次数
    int min(int a, int b);        // 返回最小值
    
private:
    set<_UINT>* chesses;    // 从棋盘全0开始，分别记录不重复地翻动1-16步可得到的所有棋盘编码
    int* steps;                // 从棋盘全0开始，到达指定棋盘状态需要翻动棋子的最小步数
};


int main(void) {
    // 一次计算把所有棋盘状态打表
    Chess* chess = new Chess();
    
    // 迭代输入棋盘状态 查表
    int chessStatus = 0;
    int byteCnt = 0;
    char byteBuff[5] = { '\0' };
    while(cin >> byteBuff && ++byteCnt) {
        int offset = 4 * (byteCnt - 1);
        for(int i = 0; i < 4; i++) {
            if(byteBuff[i] == 'w') {    // b标记为0, w标记为1
                chessStatus |= (0x00000001 << (i + offset));
            }
        }
        
        // 每输入4个字节求解一次
        if(byteCnt >= 4) {
            int step = chess->getStep(chessStatus);
            if(step >= 0) {
                cout << step << endl;
            } else {
                cout << "Impossible" << endl;
            }
            
            byteCnt = 0;
            chessStatus = 0;
        }
    }
    delete chess;
    return 0;
}


/**
 * 构造函数
 */
Chess::Chess() {
    this->chesses = new set<_UINT>[MAX_STEP + 1];
    
    this->steps = new int[MAX_STATUS];
    memset(steps, -1, sizeof(int) * MAX_STATUS);
    
    bfsAllStatus();
}


/**
 * 析构函数
 */
Chess::~Chess() {
    for(int s = 0; s <= MAX_STEP; s++) {
        chesses->clear();
    }
    delete[] chesses; chesses = NULL;
    delete[] steps; steps = NULL;
}


/**
 * 初始化不重复地翻动1-16步可得到的所有棋盘状态
 */
void Chess::bfsAllStatus(void) {
    const int ALL_ZERO_CHESS = 0;
    steps[0] = ALL_ZERO_CHESS;    // 初始状态，棋盘全黑
    chesses[0].insert(ALL_ZERO_CHESS);    // 即翻动0次的状态集
    
    // 记录以不重复的组合方式翻动1-16次的可以到达的所有状态集
    for(int filpStep = 1; filpStep <= MAX_STEP; filpStep++) {
        set<_UINT>* lastChesses = &chesses[filpStep - 1];    // 上一步的状态集
        set<_UINT>* nextChesses = &chesses[filpStep];        // 下一步的状态集
        
        // 迭代上一步每个棋盘状态，在其基础上均多翻一个棋子，作为下一步的状态集
        for(set<_UINT>::iterator its = lastChesses->begin(); its != lastChesses->end(); its++) {
            _UINT lastChess = *its;    // 上一次棋盘状态编码
            
            // 剪枝1：棋子是从低位编号开始翻动的，为了不重复翻动棋子，从上一棋盘状态的最高位编号开始翻动
            for(int pos = getMaxBitPos(lastChess) + 1; pos < MAX_STEP; pos++) {
                _UINT nextChess = filp(lastChess, pos);    // 翻动棋子得到下一个棋盘状态编码
                int status = toStatus(nextChess);        // 屏蔽高16位操作位，得到低16位的真正棋盘状态
                
                // 剪枝2：仅不重复的状态才需要登记到下一步的状态集
                // 注意这里使用steps数组进行全局状态判重，而不能仅仅使用nextStatus对本次翻动判重
                if(steps[status] < 0) {
                    steps[status] = filpStep;        // 状态首次出现的步数必定是最小步数
                    nextChesses->insert(nextChess);
                    
                } else {
                    // Undo: 重复状态不再记录到状态集
                    //  通过不同步数、翻棋组合可达到的重复状态共61440种，
                    //  总翻棋次数才65536，换言之有效状态只有4096种，
                    //  这步剪枝是很重要的，否则必定超时
                }
            }
        }
        
        // 剪枝3：当前状态集（因剪枝导致）全空，则后面所有状态集无需再计算
        if(nextChesses->empty()) {
            break;
        }
    }
}


/**
 * 翻动棋盘上某个指定位位置的棋子,
 *  此操作会同时改变棋盘编码的操作位（高16位）和状态位（低16位）
 * @param chess 翻转前的棋盘编码
 * @param bitPos 要翻转的棋子位置, 取值范围为[0, 15]，
 *                依次对应4x4棋盘上从左到右、自上而下的编号，也对应二进制数从低到高的进制位
 * return 翻转后的棋盘编码
 */
_UINT Chess::filp(_UINT chess, int bitPos) {
    _UINT OP_MASK = 0x00010000 << bitPos;        // 高16位:当前操作位
    _UINT STATUS_MASK = STATUS_MASKS[bitPos];    // 低16位:相关状态位
    return (chess ^ (OP_MASK | STATUS_MASK));    // 更新棋盘编码
}

/* 常规翻转棋子的方法，比较易懂但运算量大，不推荐
 _UINT Chess::filp(_UINT chess, int bitPos) {
 // 高16位:当前操作位
 _UINT op = 0x00010000 << bitPos;
 // 低16位:相关状态位
 const _UINT BASE = 0x00000001;
 op |= BASE << bitPos;    // 翻转棋子自身位置
 if(bitPos > 3) { op |= BASE << (bitPos - 4);  }    // 翻转棋子上方的棋子
 if(bitPos < 12) { op |= BASE << (bitPos + 4);  }    // 翻转棋子下方的棋子
 int mod = bitPos % 4;
 if(mod != 0) { op |= BASE << (bitPos - 1);  }    // 翻转棋子左方的棋子
 if(mod != 3) { op |= BASE << (bitPos + 1);  }    // 翻转棋子右方的棋子
 return chess ^ op;    // 更新棋盘编码
 }
 */

/**
 * 从棋盘编码提取棋盘状态信息
 * return 棋盘状态信息（低16位）
 */
int Chess::toStatus(_UINT chess) {
    const _UINT MASK = 0x0000FFFF;
    return (int) (chess & MASK);
}


/**
 * 从棋盘编码提取棋盘操作信息（高16位），获得其中最大翻转编号的位置
 * @param chess 棋盘编码
 * return 没有操作过则返回-1，否则返回0-15
 */
int Chess::getMaxBitPos(_UINT chess) {
    _UINT MASK = 0x80000000;
    int bitPos = -1;
    for(int i = MAX_STEP - 1; i >= 0; i--) {
        if((chess & MASK) == MASK) {    // 注意加括号, ==优先级比&要高
            bitPos = i;
            break;
        }
        MASK >>= 1;
    }
    return bitPos;
}


/**
 * 从棋盘编码提取棋盘操作信息（高16位），获取棋盘从全0状态开始共被翻动棋子的次数
 * @param chess 棋盘编码
 * return 被翻转次数
 */
int Chess::getFilpCount(_UINT chess) {
    const _UINT MASK = 0xFFFF0000;
    chess &= MASK;    // 屏蔽低16位的状态位
    
    // 判断高16位操作位有多少个1, 即为翻转次数
    int cnt = 0;
    while(chess > 0) {
        chess = (chess & (chess - 1));
        cnt++;
    }
    return cnt;
}


/**
 * 计算从全0或全1状态到达指定棋盘状态的最小步数
 * @param status 棋盘状态
 * return 最小步数（若不可达则返回-1）
 */
int Chess::getStep(int status) {
    int step = -1;
    if(status >= 0 && status < MAX_STATUS) {
        int bStep = steps[status];                // 从全0开始到达指定状态的步数
        int wStep = steps[toStatus(~status)];    // 取反，从全1开始到达状态chess的步数
        
        if(bStep >= 0 && wStep >= 0) {
            step = min(bStep, wStep);
            
        } else if(bStep >= 0) {
            step = bStep;
            
        } else if(wStep >= 0) {
            step = wStep;
        }
    }
    return step;
}


/**
 * 返回最小值
 * @param a 参数a
 * @param b 参数b
 * return 最小值
 */
int Chess::min(int a, int b) {
    return (a <= b ? a : b);
}


