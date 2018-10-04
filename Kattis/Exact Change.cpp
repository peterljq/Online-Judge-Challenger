#include <iostream>

using namespace std;

#define inf 99999

int main(){
    int T;
    scanf("%d", &T);
    int needtopay, N;
    int M[10001], A[101];
    //A to record the notes that I have.
    //M is the dp table
    //Use 1-dimension array because want to find the minimum number of notes (Overwrite to update.)
    while(T--){
        cin >> needtopay;
        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> A[i];
        }
        for(int i = 1; i <= 10000; i++){
            M[i] = inf;
        }
        M[0] = 0;
        
        for(int i = 1; i <= N; i++){
            for(int j = 10000; j > 0; j--){
                if(j - A[i] >= 0){
                    M[j] = min(M[j - A[i]] + 1,M[j]);
                    //first time will meet the inf=99999, definitely got a solution (possibly not optimized)
                    //later when facing a new note, the total number by using the note is less than current, thus update.
                }
            }
        }
        int i;
        for(i = needtopay; M[i] == inf; i++);
        //to find the closest amount to needtopay
        cout << i << " " << M[i] << endl;
        
    }
    
    return 0;
}
