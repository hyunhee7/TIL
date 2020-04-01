// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = -1;
    //n, n+1의 차이가 1 , 다음 -1 연속

    //변곡확인
    bool isFin = true;
    int val1 = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        if (val1 == 0) {
            val1 = A[i + 1] - A[i];
            if (val1 == 0) {
                isFin = false;
                break;
            }else
                continue;
        }
        else {
            int k = A[i + 1] - A[i];
            if (k > 0 && val1 < 0) {
                val1 = k;
            }
            else if (k < 0 && val1>0) {
                val1 = k;
            }
            else {
                isFin = false;
            }
        }
        if (!isFin)break;
    }
    if (isFin) {
        return 0;
    }
    else {
        //제외할 인덱스
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            int val = 0;
            bool Impossible = false;
            for (int j = 0; j < A.size() -1; j++) {
                if (i == j) continue;
                if (val == 0) {
                    if (j + 1 == i) {
                        val = A[j + 2] - A[j];
                    }else
                        val = A[j + 1] - A[j];
                    if (val == 0) {
                        Impossible = true;
                        break;
                    }
                    continue;
                }
                if (j + 1 == i) {
                    if (j + 2 >= A.size()) continue;
                    int k = A[j + 2] - A[j];
                    if (k > 0 && val < 0) {
                        val = A[j + 2] - A[j];
                    }
                    else if (k < 0 && val>0) {
                        val = A[j + 2] - A[j];
                    }
                    else Impossible = true;
                    
                }
                else {
                    int k = A[j + 1] - A[j];
                    if (k > 0 && val < 0) {
                        val = A[j + 1] - A[j];
                    }
                    else if (k < 0 && val>0) {
                        val = A[j + 1] - A[j];
                    }
                    else Impossible = true;
                }
            }
            if (!Impossible) {
                //cout << i << endl;
                result++;
            }
        }
        if (result == 0) return -1;
        else return result;
    }
    return answer;
}

int main() {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<int> d;
    a = { 3,4,5,3,7 };
    b = { 1,3,1,2 };
    c = { 1,2,3,4 };
    d = { 2,2,2,2 };
    int res = solution(d);
    cout << res << endl;
}