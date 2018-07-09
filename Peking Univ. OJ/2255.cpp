
/*
 题意分析：
 给出一棵二叉树的前序遍历与中序遍历，求后序遍历.
 其中二叉树由不重复的大写字母组成，每个节点一个字母.
 解题思路：
 ① 前序遍历的第一个字母必是 根
 ② 在中序遍历的字母串中找出 根字母，那么根字母左右两边的字符串就分别是它的左、右子树
 ③ 由于树的最大深度只有26，因此可以不考虑堆栈溢出，利用[递归]结合①②复原二叉树
 ④ 对复原的二叉树使用DFS做后序遍历即可
 注：
 对二叉树的 前序遍历、中序遍历、后序遍历 均可以使用DFS来做，
 均是自上而下、自左至右遍历，区别在于打印节点的时机不同：
 [前序遍历] 从父节点进入时打印当前节点
 [中序遍历] 从左子树返回时打印当前节点
 [后序遍历] 从右子树返回时打印当前节点
 */

#include <memory.h>
#include <iostream>
using namespace std;

const static int STR_LEN = 27;        // 树遍历序列最大长度
const static char NULL_CHAR = '\0';    // 空字符

// 节点结构
class Node {
public:
    char name;        // 节点名称
    Node* left;        // 左子树根节点
    Node* right;    // 右子树根节点
    
    Node(): name(NULL_CHAR), left(NULL), right(NULL) {}
    ~Node() {
        name = NULL_CHAR;
        delete left; left = NULL;
        delete right; right = NULL;
    }
};


/*
 * 根据前序序列与中序序列还原二叉树
 * @param preOrder 前序遍历序列
 * @param inOrder 中序遍历序列
 * return 所构造树的根节点
 */
Node* createTree(char* preOrder, char* inOrder);


/*
 * DFS遍历树，构造后序序列
 * @param root 树根节点
 * @param _out_postOrder 后序序列
 */
void dfs(Node* root, char* _out_postOrder);


int main(void) {
    char preOrder[STR_LEN] = { NULL_CHAR };
    char inOrder[STR_LEN] = { NULL_CHAR };
    
    while(cin >> preOrder >> inOrder) {
        Node* root = createTree(preOrder, inOrder);    // 构造二叉树
        char postOrder[STR_LEN] = { NULL_CHAR };    // 后序序列
        dfs(root, postOrder);    // DFS遍历树，生成后序序列
        cout << postOrder << endl;
        
        delete root;
        memset(preOrder, NULL_CHAR, sizeof(char) * STR_LEN);
        memset(inOrder, NULL_CHAR, sizeof(char) * STR_LEN);
    }
    return 0;
}


Node* createTree(char* preOrder, char* inOrder) {
    const int LEN = strlen(preOrder);
    if(LEN <= 0) {
        return NULL;
    }
    
    Node* root = new Node();
    root->name = *preOrder;    // 前序遍历的第一个节点必定是树根
    
    char* leftPreOrder = new char[LEN + 1];        // 左子树前序列
    char* leftInOrder = new char[LEN + 1];        // 左子树中序列
    char* rigntPreOrder = new char[LEN + 1];    // 右子树前序列
    char* rigntInOrder = new char[LEN + 1];        // 右子树中序列
    
    // 使左/右子树的前/中序列与根节点的树序列一直，后面再根据根节点的位置进行序列截取
    strcpy(leftPreOrder, preOrder);
    strcpy(leftInOrder, inOrder);
    strcpy(rigntPreOrder, preOrder);
    strcpy(rigntInOrder, inOrder);
    
    // 根据根节点在中序序列的位置，调整左右子树的前序序列和中序序列范围
    for(int i = 0; *(inOrder + i) != NULL_CHAR; i++) {
        if(root->name == *(inOrder + i)) {
            *(leftInOrder + i) = NULL_CHAR;                // 标记左子树[中序序列]的结束点
            int leftLen = strlen(leftInOrder);            // 左子树节点数
            *(leftPreOrder + leftLen + 1) = NULL_CHAR;    // 标记左子树[前序序列]的结束点
            
            Node* leftTree = createTree((leftPreOrder + 1), leftInOrder);    // 生成左子树
            Node* rightTree = createTree(
                                         (rigntPreOrder + leftLen + 1), (rigntInOrder + i + 1));        // 生成右子树
            root->left = leftTree;
            root->right = rightTree;
            break;
        }
    }
    
    // 注：前面在标记左/右子树序列的起始位置时，不能变更数组指针地址，否则这里无法释放内存
    delete[] leftPreOrder;
    delete[] leftInOrder;
    delete[] rigntPreOrder;
    delete[] rigntInOrder;
    return root;
}


void dfs(Node* root, char* _out_postOrder) {
    if(root == NULL) {
        return;
    }
    
    dfs(root->left, _out_postOrder);
    dfs(root->right, _out_postOrder);
    
    // 构造后序序列：从右子树返回时把当前节点名称放到序列末尾
    *(_out_postOrder + strlen(_out_postOrder)) = root->name;
}

