//
//  main.cpp
//  Algo
//
//  Created by Luo Jinqi on 21/8/18.
//  Copyright © 2018 Luo Jinqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MAXN 100001

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    int first[M];
    int second[M];
    int cut[Q];
    int result = 0;
    int output[Q];
    int accumulate[N+1];
    for(int i = 0; i < N + 1; i++){
        accumulate[i] = 0;
    }
    for(int i = 0; i < M; i++){
        cin >> first[i];
        cin >> second[i];
    }
    for(int i = 0; i < Q; i++){
        cin >> cut[i];
        for(int j = 0; j < M; j++){
            for(int k = first[j]; k <= second[j]; k++){
                accumulate[k] ++;
            }
        }
        output[i] = accumulate[cut[i]];
        for(int p = 0; p < N + 1; p++){
            accumulate[p] = 0;
        }
    }
    for(int i = 0; i < Q; i++){
        cout << output[i] << endl;
    }
    
}



