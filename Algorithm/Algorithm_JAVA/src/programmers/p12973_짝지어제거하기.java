package programmers;
import java.util.*;
public class p12973_짝지어제거하기 {
    public int solution(String s)
    {
        int answer = 0;
        Stack<Character> st = new Stack<>();
        char[] c = s.toCharArray();
        for(int i=0;i<c.length;i++){
            if(!st.isEmpty()){
                if(st.peek()==c[i]){
                    st.pop();
                    continue;
                }
            }
            st.push(c[i]);
        }
        if(st.isEmpty()) answer = 1;
        return answer;
    }
}
