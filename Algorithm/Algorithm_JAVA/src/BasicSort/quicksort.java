package BasicSort;

import java.util.Arrays;

public class quicksort {
	static int partition(int[] arr,int start, int end) {
		int pivot = arr[(start+end)/2];
		while(start<=end) {
			while(arr[start]<pivot) start++;
			while(arr[end]>pivot) end--;
			if(start<=end) {
				int tmp = arr[start];
				arr[start]=arr[end];
				arr[end]=tmp;		
				start++;
				end--;
			}
		}
		return start;
	}
	static int[] quick(int[] arr,int start, int end) {
		int part = partition(arr, start, end);
		if(start<part-1) 
			quick(arr,start,part-1);
		if(part<end)
			quick(arr,part,end);
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {9,3,2,4,1,5,7,6,8};
		arr = quick(arr,0,arr.length-1);
		System.out.println(Arrays.toString(arr));		
	}

}
