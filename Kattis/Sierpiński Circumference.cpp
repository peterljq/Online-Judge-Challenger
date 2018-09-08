#include <iostream>
#include <map>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#define ll long long
#define intt long long
#define LOG3 0.4771212547196624372950279032551153092001288641907
#define LOG(three_over_two) 0.17609125905568124208128900853062228243193898272859
using namespace std;



int main()
{
    int casenum = 0;
    int dividenum = 0;
    int digitnum = 0;
    while(cin >> dividenum){
        digitnum = 1 + LOG3 + dividenum*LOG(three_over_two);
        cout << "Case " << ++casenum << ": " << digitnum << endl;
    }
}


