package BasicSort;

import java.util.Arrays;

public class selectsort {
	static int[] selection(int[] arr) {
		
		for(int i=0;i<arr.length-1;i++) {
			int min = i;
			for(int j=i+1;j<arr.length;j++) {
				if(arr[min]>arr[j])
					min = j;
			}
			int now = arr[i];
			arr[i] = arr[min];
			arr[min] = now;
		}
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {9,3,2,4,1,5,7,6,8};
		arr = selection(arr);
		System.out.println(Arrays.toString(arr));
	}

}
