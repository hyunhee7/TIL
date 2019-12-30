package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p13458 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(),"");
		long n = Integer.parseInt(st.nextToken());
		long[] map = new long[(int)n];
		long answer = 0;
		st = new StringTokenizer(br.readLine()," ");
		int idx = 0;
		while(st.hasMoreTokens()) {
			map[idx] = Integer.parseInt(st.nextToken());
			idx+=1;
		}
		st = new StringTokenizer(br.readLine()," ");
		long b = Integer.parseInt(st.nextToken());
		long c= Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			if(map[i]>0) {
				map[i]-=b;
				answer++;
			}
		}
		for(int i=0;i<n;i++) {
			if(map[i]<=0) continue;
			long p = (long) Math.floor(map[i]/c);
			//System.out.println("p: "+p);
			long q = map[i]%c;
			if(q>0) {
				answer+=(p+1);
			}else {
				answer+=p;
			}
		}
		System.out.println(answer);
	}

}
