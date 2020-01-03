package BasicSort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Fibonacci {
	public static int fi(int n) {
		if(n==0)
			return 0;
		if(n==1)
			return 1;
		return fi(n-1)+fi(n-2);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int res = fi(n);
		System.out.println(res);
	}

}
