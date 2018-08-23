#include <iostream>

using namespace std;

void merge(int a[], int lefts, int lefte, int rights, int righte);
void mergesort(int k[], int start, int end);

int main(){
    int a[] = {3,0,1,2,5,7,11,3,2};
    mergesort(a,0,8);
    for(int i = 0; i < 9; i++){
        cout << a[i] << " ";
    }
}

//assume that 2 partions (left part and right part) are sorted subarrays, then this func can merge them into a sorted array.
void merge(int k[], int lefts, int lefte, int rights, int righte){
    int size = lefte - lefts + 1 + righte - rights + 1;
    int temp[size];
    int astart = lefts;
    int bstart = rights;
    int aend = lefte;
    int bend = righte;
    for(int i = 0; i < size; i++){
        if(astart <= aend && k[astart] <= k[bstart]){
            temp[i] = k[astart++];
        }
        else if(bstart <= bend && k[astart] > k[bstart]){
            temp[i] = k[bstart++];
        }
        else if(astart > aend){
            temp[i] = k[bstart++];
        }
        else{
            temp[i] = k[aend++];
        }
    }
    for(int i = lefts; i < lefts + size; i++){
        k[i] = temp[i - lefts];
    }
}

//Recursion inplementation of MergeSort
void mergesort(int k[], int start, int end){
    if(end - start > 1){
        mergesort(k, start, (start + end)/2);
        mergesort(k, 1 + (start + end)/2, end);
    }
    merge(k,start, (start + end)/2,1 + (start + end)/2, end);
}
