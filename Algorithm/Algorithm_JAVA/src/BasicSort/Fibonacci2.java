package BasicSort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Fibonacci2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] fi = new int[n+1];
		fi[0]=0;fi[1]=1;
		for(int i=2;i<=n;i++) {
			fi[i]=fi[i-1]+fi[i-2];
		}
		System.out.println(fi[n]);
	}
}
