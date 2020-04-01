// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int>& A) {
    vector<int>sum;
    int maxsum = -1;
    for (int i = 0; i < A.size(); i++) {
        sum.push_back(A[i] / 10 + A[i] % 10);
    }
    for (int i = 0; i < sum.size(); i++) {
        for (int j = i + 1; j < sum.size(); j++) {
            if (sum[i] == sum[j]) {
                if (A[i] + A[j] > maxsum) {
                    maxsum = A[i] + A[j];
                }
            }
        }
    }
    return maxsum;
}

int main() {
    vector<int> A = { 51,32,43 };
    cout << solution(A) << endl;

    return 0;
}