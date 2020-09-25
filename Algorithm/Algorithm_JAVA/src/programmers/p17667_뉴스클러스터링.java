package programmers;

import java.io.IOException;
import java.util.*;

public class p17667_뉴스클러스터링 {
    public static int solution(String str1, String str2) {
        int answer = 0;
        ArrayList<String> str1Arr = new ArrayList<>();
        ArrayList<String> str2Arr = new ArrayList<>();
        ArrayList<String> union = new ArrayList<>();
        ArrayList<String> intersection = new ArrayList<>();

        //1. 두글자씩 다중집합을 만든다.
        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();
        for (int i = 0; i < str1.length() - 1; i++) {
            if (str1.charAt(i) == ' ' || str1.charAt(i + 1) == ' ' || !Character.isLetter(str1.charAt(i)) || !Character.isLetter(str1.charAt(i + 1)))
                continue;
            String val = String.valueOf(str1.charAt(i)) + String.valueOf(str1.charAt(i + 1));
            str1Arr.add(val);
        }
        for (int i = 0; i < str2.length() - 1; i++) {
            if (str2.charAt(i) == ' ' || str2.charAt(i + 1) == ' ' || !Character.isLetter(str2.charAt(i)) || !Character.isLetter(str2.charAt(i + 1)))
                continue;
            String val = String.valueOf(str2.charAt(i)) + String.valueOf(str2.charAt(i + 1));
            str2Arr.add(val);
        }
        //2.sort
        Collections.sort(str1Arr);
        Collections.sort(str2Arr);

        //3.교집합
        for (String s : str1Arr) {
            if (str2Arr.remove(s)) {
                intersection.add(s);
            }
            union.add(s);
        }

        //4.합집합
        for (String s : str2Arr) {
            union.add(s);
        }
        double res = 0;
        if (union.size() == 0) {
            res = 1;
        } else {
            res = (double) intersection.size() / (double) union.size();
        }
        answer = (int)(res*65536);
        return answer;
    }

    public static void main(String[] args) throws IOException {
        String str1 = "FRANCE";
        String str2 = "french";
        System.out.println(solution(str1, str2));
    }
}
