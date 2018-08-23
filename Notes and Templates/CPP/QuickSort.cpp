void quicksort(int a[],int start,int end,int *swaptimes){
    int left = start;
    int right = end;
    int pivot = (start + end) / 2;
    if(left >= right){}
    else{
        while(left <= right && a[left] < a[pivot]){
            left ++;
        }
        while(left <= right && a[right] > a[pivot]){
            right --;
        }
        if(left <= right){
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
            if(left != right){
                (*swaptimes) ++;
            }
            left ++;
            right --;
        }
        quicksort(a, start, right, swaptimes);
        quicksort(a, left, end, swaptimes);
    }
}
