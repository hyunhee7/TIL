package BasicSort;

import java.util.Arrays;

public class bubblesort {
	public static int[] bubble(int[] arr) {
		for(int i=0;i<arr.length-1;i++) {
			for(int j=0;j<arr.length-i-1;j++) {
				if(arr[j]>arr[j+1]) {
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
				System.out.println(Arrays.toString(arr));
			}
		}
		
		return arr;
	}
	public static void main(String[] args) {
		int[] arr = {9,3,2,4,1,5,7,6,8};
		
		arr = bubble(arr);
		System.out.println(Arrays.toString(arr));
	}

}
