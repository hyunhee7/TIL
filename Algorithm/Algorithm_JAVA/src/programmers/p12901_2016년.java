package programmers;

public class p12901_2016년 {
    public String solution(int a, int b) {
        String answer = "";
        int[] full = {31,29,31,30,31,30,31,31,30,31,30,31};
        String[] week = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
        if(a>1){
            for(int i=0;i<a-1;i++){
                b+=full[i];
            }
        }
        int val = b%7;
        if(val==0) val = 7;
        answer = week[val-1];
        return answer;
    }
}
