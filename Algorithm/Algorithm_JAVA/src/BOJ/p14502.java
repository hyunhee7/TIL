package BOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class p14502 {
	static boolean[][] visited;
	static int[][] map;
	static int n,m;
	static int answer =0 ;
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
	static ArrayList<int[]> virus;
	public static void spread(int[][] map2,boolean[][] visited2,int x, int y) {
		for(int i=0;i<4;i++) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx<0||ny<0||nx>=n||ny>=m) continue;
			if(!visited2[nx][ny] && map2[nx][ny]==0) {
				visited2[nx][ny]=true;
				map2[nx][ny]=2;
				spread(map2,visited2,nx,ny);
			}
		}
	}
	public static void dfs(int x, int y, int cnt) {
		if(cnt==3) {
			int[][] map2 = new int[n][m];
			boolean[][] visited2 = new boolean[n][m];
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					map2[i][j]=map[i][j];
				}
			}
			for(int i=0;i<virus.size();i++) {
				int[] tmp=virus.get(i);
				spread(map2,visited2,tmp[0],tmp[1]);
			}
			int res=0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(map2[i][j]==0) {
						res++;
					}
				}
			}
			if(res>answer)answer=res;
			return;
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(map[i][j]==0 && !visited[i][j]) {
					visited[i][j]=true;
					map[i][j]=1;
					dfs(i,j,cnt+1);
					visited[i][j]=false;
					map[i][j]=0;
				}
			}
		}		
	}
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visited = new boolean[n][m];
		virus = new ArrayList<int[]>();
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				map[i][j]=Integer.parseInt(st.nextToken());
				if(map[i][j]==2) {
					int[] tmp = new int[2];
					tmp[0]=i;
					tmp[1]=j;
					virus.add(tmp);
				}
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(map[i][j]==0 && !visited[i][j]) {
					visited[i][j]=true;
					map[i][j]=1;
					dfs(i,j,1);
					visited[i][j]=false;
					map[i][j]=0;
				}
			}
		}
		
		System.out.println(answer);
	}
}