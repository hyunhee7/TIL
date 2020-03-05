#include <iostream>
using namespace std;
int dx[] = { 1,2,4 };
string solution(int n) {
    string answer = "";
    int c;
    while (n>0) {
        c = n % 3;
        n = n / 3;
        if (c == 0) {
            n -= 1;
            c = 4;
        }
        char tmp = c + '0';
        answer = tmp + answer;
    }
    return answer;
}
int main() {
    int n = 4;
    solution(n);

}