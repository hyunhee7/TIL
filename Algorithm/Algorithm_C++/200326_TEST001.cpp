#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
string line;
long answer = 0;
int n, k;
void calc(int start) {
    long val = 0;
    for (int i = 0; i < k; i++) {
        long num = line[start + i] - '0';
        if (i == k - 1) {
            val += num;
        }
        else
            val += (num * pow(10, (k - i - 1)));
    }
    if (val >= answer) {
        answer = val;
    }
}
int main() {
    cin >> n >> k;
    cin >> line;
    for (int i = 0; i <= n - k; i++) {
        calc(i);
    }
    cout << answer;
}