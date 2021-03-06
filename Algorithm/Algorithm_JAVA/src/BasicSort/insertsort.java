package BasicSort;

import java.util.Arrays;

public class insertsort {
	static int[] insertion(int[] arr) {
		for(int i=1;i<arr.length;i++) {
			int key = arr[i];
			int j = i-1;
			while(j>=0 && key<arr[j]) {
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = key;
		}
		
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {9,3,2,4,1,5,7,6,8};
		arr = insertion(arr);
		System.out.println(Arrays.toString(arr));
	}

}
