package programmers;
import java.util.*;
public class p43162_네트워크 {
    static boolean[][] visited;
    static boolean[] v;
    public void DFS(int x, int[][] computers){
        v[x] = true;
        for(int i=0;i<computers.length;i++){
            if(i!=x && computers[x][i]==1 && !visited[x][i]){
                visited[x][i] = true;
                visited[i][x] = true;
                DFS(i,computers);
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        v = new boolean[computers.length];
        visited = new boolean[computers.length][computers.length];
        for(int i=0;i<computers.length;i++){
            for(int j=0;j<computers[i].length;j++){
                if(i!=j && computers[i][j]==1 && !visited[i][j]){
                    v[i] = true;
                    answer++;
                    visited[i][j] = true;
                    visited[j][i] = true;
                    DFS(j,computers);
                }
            }
        }
        System.out.println(Arrays.toString(v));
        for(int i=0;i<computers.length;i++){
            if(!v[i]) answer++;
        }
        return answer;
    }
}
