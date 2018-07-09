
/*
 题意分析：
 给定一个直角坐标系，定义x轴为海岸线，海岸线上方是海，下方是陆地.
 在海域零星分布一些海岛, 需要要在海岸线上安装若干个雷达覆盖这些海岛,
 每个雷达的覆盖半径都是相同且固定的.
 现在给定所有海岛的坐标(x,y), 以及雷达的覆盖半径d，
 问可以覆盖所有海岛的最小雷达数.
 解题思路：
 首先可以明确的是：只要存在任意一个海岛位置超出雷达最大覆盖半径（即y>d），则无解.
 在所有海岛的 y<=d 的前提下去思考此问题，
 那么此问题的切入点是需要知道【一个雷达要覆盖一个海岛，其可以安装范围是多少】
 以海岛坐标(x,y)为圆心，用雷达覆盖半径d画圆，根据前提条件可知，
 这个圆与x轴必定存在最少1个(y=d)、最多2个交点(y<d).
 可以认为1个交点是2个交点重合的特殊情况，那么这2个交点在x轴上构成的线性区间，
 可以看作海岛的被覆盖范围在x轴上的投影 (由此就可以把二维的几何问题转化成一维几何问题)
 按照所有海岛的x轴坐标，从小到大依次计算每个海岛在x轴上的投影区间（投影可能存在重叠），
 同时把每个雷达抽象成1个点，那么此问题就转化成：
 【已知x轴上若干个区间（可能存在交集），现在要往这些区间内放若干个点，
 问怎样放置这些点，使得每个区间内至少存在一个点，且所放置的点的总量尽可能最少】
 
 
 可使用贪心算法求解：
 根据每个区间的左端点坐标对所有区间从左到右排序:
 ① 在左起第一个区间A 的右端点 A.R 放置一个点，总放置点数 P+1
 ② 若下一个区间B 的左端点 B.L > A.R,
 说明 区间A 与 区间B 无交集，此时在区间B 的右端点 B.R 放置一个点，总放置点数 P+1
 否则说明 区间A 与 区间B 相交, 此时进一步判断，若 B.R < A.R，
 说明 区间B 在 区间A 的内部，此时把原本放置在 A.R 的点移动到 B.R（确保区间B有一个点），总放置点数不变
 ③ 重复这个过程直到所有区间被遍历完成
 */


#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;


// 海岛在x轴上的投影区间
struct Interval {
    double left;    // 左端点在x轴上的坐标
    double right;    // 右端点在x轴上的坐标
};


/*
 * 求解问题：在每个区间内至少放置一个点，使得放置的点的总量最少
 * @param intervals 区间集合
 * @param size 区间个数
 * return 最小的放置点数
 */
int solve(Interval* intervals, int size);


/*
 * 比较两个区间的大小（用于排序）
 *  左端点越小的区间，该区间的顺次越小
 * @param a 区间a
 * @param b 区间b
 * return a.left <= b.left
 */
bool compare(Interval a, Interval b);


int main(void) {
    int island, radius, testCase = 0;
    while((cin >> island >> radius) && island && radius) {
        const double R2 = radius * radius;    // 半径平方
        Interval* intervals = new Interval[island];
        
        bool isSolvable = true;
        for(int i = 0; i < island; i++) {
            double x, y;
            cin >> x >> y;
            if(y > radius) {    // 存在海岛不在雷达的最大影响范围，无解
                isSolvable = false;
            }
            
            double offset = sqrt(R2 - y * y);    // 勾股定理
            intervals[i].left = x - offset;
            intervals[i].right = x + offset;
        }
        
        int minRadar = (isSolvable ? solve(intervals, island) : -1);
        cout << "Case " << ++testCase << ": " << minRadar << endl;
        delete[] intervals;
    }
    return 0;
}


int solve(Interval* intervals, int size) {
    sort(intervals, intervals + size, compare);
    
    int minPoint = 1;
    double right = intervals[0].right;
    for(int i = 1; i < size; i++) {
        
        // 区间i-1 与 区间i 无交集
        if(intervals[i].left > right) {
            minPoint++;
            right = intervals[i].right;
            
            // 区间i-1 在 区间i 内部
        } else if(intervals[i].right < right) {
            right = intervals[i].right;
            
        } else {
            // Undo: 区间i-1 与 区间i 相交
        }
    }
    return minPoint;
}


bool compare(Interval a, Interval b) {
    return a.left <= b.left;
}

