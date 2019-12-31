package BasicSort;

import java.util.Arrays;

public class mergesort {
	public static int[] merge(int[] arr, int[] tmp, int start, int mid, int end) {
		for(int i=start;i<=end;i++) {
			tmp[i] = arr[i];
		}
		int s1 = start;
		int s2 = mid+1;
		int index = start;
		while(s1<=mid && s2<=end) {
			if(tmp[s1]<=tmp[s2]) {
				arr[index] = tmp[s1];
				s1++;
			}else {
				arr[index] = tmp[s2];
				s2++;
			}
			index++;
		}
		for(int i=0;i<=mid-s1;i++) {
			arr[index+i] = tmp[s1+i];
		}
		return arr;
	}
	public static int[] mergeSort(int[] arr, int[] tmp, int start, int end) {
		if(start<end) {
			int mid = (start+end)/2;
			
			mergeSort(arr,tmp,start,mid);
			mergeSort(arr,tmp,mid+1,end);
			arr = merge(arr,tmp,start,mid,end);			
		}
		return arr;
	}
	
	public static int[] mergeSort(int[] arr) {
		int[] tmp = new int[arr.length];
		arr = mergeSort(arr,tmp,0,arr.length-1);
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {9,3,2,4,1,5,7,6,8};
		arr = mergeSort(arr);
		System.out.println(Arrays.toString(arr));	
	}

}
