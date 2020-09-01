package programmers;

import java.util.Collection;

public class p62048_멀쩡한사각형 {
    /*방법 2*/
    public static long gcd2 (long w, long h){
        if(h>0){
            return gcd2(h, w%h);
        }else
            return w;
    }
    public static long solution2(int w, int h) {
        long answer = 0;
        long gcd = gcd2(w, h);
        answer = ((long)w*(long)h)-((long)w+(long)h-gcd);
        return answer;
    }

    /*방법 1*/
    public static long gcd(long wVal, long hVal) {
        long tmp = wVal;
        if (wVal > hVal) {
            wVal = hVal;
            hVal = tmp;
        }
        long cnt = 0;
        long gc = 1;
        while (++cnt <= wVal) {
            long tw = wVal;
            long hw = hVal;
            if (tw % cnt == 0 && hw % cnt == 0) {
                gc = cnt;
            }
        }
        return gc;
    }

    public long solution(int w, int h) {
        long answer = 1;
        long val = 0;
        long wVal = Long.parseLong(String.valueOf(w));
        long hVal = Long.parseLong(String.valueOf(h));
        //1. val = (가로+세로) - gcd
        if (w == h) {
            val = w + h - w;
        } else if (w == 1 || h == 1) val = w * h;
        else val = wVal + hVal - gcd(wVal, hVal);
        //2. answer = 가로 * 세로 - val
        answer = wVal * hVal - val;
        return answer;
    }
}
