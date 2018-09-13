long long fac(int k, double max){
    int a = k;
    long long array[1000000];
    array[0] = 1;
    for(long long i = 1; i <= a;i++){
        array[i] = array[i-1] * i;
        if(array[i] > max)
            return (long long) max+5;
    }
    return array[a];
}
