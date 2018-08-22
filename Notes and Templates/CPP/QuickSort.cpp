void quicksort(int arr[], int start, int end){
    if(start >= end){}
    else{
        int left = start;
        int right = end;
        int pivot = (start + end)/2;
        while(left <= right && arr[left] < arr[pivot]){
            left ++;
        }
        while(left <= right && arr[right] > arr[pivot]){
            right --;
        }
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
        quicksort(arr, left, end);
        quicksort(arr, start, right);
    }
}
