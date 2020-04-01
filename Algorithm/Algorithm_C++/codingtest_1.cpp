// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int val[100001] = { 0, };
    int maxnum = 0;
    for (int i = 0; i < A.size(); i++) {
        val[A[i]]++;
        if (A[i] > maxnum) maxnum = A[i];
    }
    int answer = 0;
    for (int i = 1; i <= maxnum; i++) {
        if (val[i] == i) answer = i;
    }
    return answer;
}

int main() {
    vector<int> a;
    a = { 3,8,2,3,3,2 };
    int res = solution(a);
    cout << res << endl;
}