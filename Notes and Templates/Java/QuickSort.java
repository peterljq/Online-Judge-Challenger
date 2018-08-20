public class QuickSort {
	public static void main(String args[]){
		
		int[] a = {2,7,3,9,8,1,10,5,16,77,98,12};
		quicksort(a,0,a.length - 1);
		for(int i = 0; i < a.length; i++) {
			System.out.print(" " + a[i] + " ");
		}
        System.out.println();

	}
	
	public static void quicksort(int[] a,int start,int end) {
		if(start >= end || a.length == 1) {
			return;
		}
		else {
			int left = start;
			int right = end;
			int pivot = (left + right)/2;
			while(left <= right && a[left] < a[pivot]) {
				left++;
			}
			while(left <= right && a[right] > a[pivot]) {
				right--;
			}
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
			quicksort(a,start,right);
			quicksort(a,left,end);
		}
	}

}
