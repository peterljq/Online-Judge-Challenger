#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int totalcase;
    int N, numofdecrease;
    int count = 0;
    int output = 0;
    int a[90000];
    cin >> totalcase;
    int casenowat;
    for(int c = 0; c < totalcase; c++){
        cin >> casenowat >> N >> numofdecrease;
        for(int i = 0; i < N; i++){
            a[i] = i+1;
        }
        do {
            for(int i = 0; i < N - 1; i++){
                if(a[i] > a[i + 1]) count++;
            }
            if(count == numofdecrease){
                output ++;
            }
            count = 0;
        }while (next_permutation(a, a + N));
        cout << casenowat << " " << output << endl;
        for(int i = 0; i < N; i++){
            a[i] = 0;
        }
        output = 0;
    }
}
