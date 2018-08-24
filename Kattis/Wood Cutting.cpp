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
    long N;
    cin >> N;
    long customernum,woodpiecenum,eachpiecesize;
    long customertime[MAXN];
    long totaltime = 0;
    double result[N];
    for(long i = 0; i < N; i++){
        cin >> customernum;
        for(long j = 0; j < customernum; j ++){
            cin >> woodpiecenum;
            customertime[j] = 0;
            for(long k = 0; k < woodpiecenum; k ++){
                cin >> eachpiecesize;
                customertime[j] += eachpiecesize;
            }
        }
        sort(customertime,customertime + customernum);
        for(long j = 0; j < customernum; j ++){
            totaltime += (customernum - j) * customertime[j];
        }
        result[i] = (double) totaltime / customernum;
        totaltime = 0;
        customernum = 0;
    }
    for(long i = 0; i < N; i++){
        printf("%.10lf\n",result[i]);
    }
}



