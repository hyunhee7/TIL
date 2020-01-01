package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p14499 {
	static int[] dx = {0,0,0,-1,1};
	static int[] dy = {0,1,-1,0,0};
	static int top = 0; //ÁÖ»çÀ§ ÁÂÇ¥
	static int down = 0;
	static int east = 0;
	static int west = 0;
	static int north = 0;
	static int south = 0;
	
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[][] map = new int[n][m];
		int[] order = new int[k];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<k;i++) {
			order[i]=Integer.parseInt(st.nextToken());
		}
		//System.out.println(Arrays.toString(order));
		for(int i=0;i<k;i++) {
			//System.out.println("hi");
			int nx = x+dx[order[i]];
			int ny = y+dy[order[i]];
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			//System.out.println("nx: "+nx+" ny: "+ny);
			//¿ì
			if(order[i]==1) {
				int temp = top;
				top = west;
				west = down;
				down = east;
				east = temp;
			//ÁÂ
			}else if(order[i]==2){
				int temp = top;
				top = east;
				east = down;
				down = west;
				west = temp;
			//»ó
			}else if(order[i]==3) {
				int temp = top;
				top = south;
				south = down;
				down = north;
				north = temp;
			//ÇÏ
			}else {
				int temp = top;
				top = north;
				north = down;
				down = south;
				south = temp;
			}
			
			if(map[nx][ny]==0) {
				map[nx][ny] = down;
			}else {
				down = map[nx][ny];
				map[nx][ny] = 0;
			}
			x=nx;
			y=ny;
			System.out.println(top);
		}
	}
}