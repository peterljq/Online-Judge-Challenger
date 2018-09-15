#include<iostream>
#include<vector>
#include <set>
#include<algorithm>

using namespace std;

int count = 0;

    
    //从vec的[start,vec.size()-1]范围内选取k个数，tmpres是当前组合
    //times是上一个元素出现的次数
    void helper(vector<int> &vec, int start, int k, int times, vector<int> &tmpres, int *count)
    {
        if(vec.size()-start < k)return;
        if(k == 0)
        {
            for(int i = 0; i < tmpres.size(); i++){
                
                
                }
            
           
            (*count)+=1;
            return;
        }
        if(start == 0 || vec[start] != vec[start-1])//当前元素前面没有出现过
        {
            //选择vec[start]
            tmpres.push_back(vec[start]);
            helper(vec, start+1, k-1, 1, tmpres, count);
            tmpres.pop_back();
            //不选择vec[start]
            helper(vec, start+1, k, 1, tmpres, count);
        }
        else//当前元素前面出现过
        {
            if(tmpres.size() >= times && tmpres[tmpres.size()-times] == vec[start])
            {
                //只有当tmpres中包含times个vec[start]时，才选择vec[start]
                tmpres.push_back(vec[start]);
                helper(vec, start+1, k-1, times+1, tmpres, count);
                tmpres.pop_back();
            }
            helper(vec, start+1, k, times+1, tmpres, count);
        }
    }
    
void combine(vector<int> &vec, int k, int *count) {
    if(k > vec.size())return;
    sort(vec.begin(), vec.end());
    vector<int>tmpres;
    helper(vec, 0, k, 0, tmpres, count);
   
}
int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> sample;
    int count = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            sample.push_back(i);
        }
    }
    combine(sample, K, &count);
    cout << count % 1000007 <<endl;
    return 0;
}
