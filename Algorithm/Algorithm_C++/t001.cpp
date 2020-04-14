#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string inputString) {
    int answer = 0;
    queue<int> box1, box2, box3, box4;
    for (int i = 0; i < inputString.size(); i++) {
        if (inputString[i] == '(') {
            box1.push(i);
        }
        else if (inputString[i] == '{') {
            box2.push(i);
        }
        else if (inputString[i] == '[') {
            box3.push(i);
        }
        else if (inputString[i] == '<') {
            box4.push(i);
        }
        if (inputString[i] == ')') {
            if (!box1.empty()) {
                box1.pop();
                answer++;
            }
            else return -1;
        }
        else if (inputString[i] == '}') {
            if (!box2.empty()) {
                box2.pop();
                answer++;
            }
            else return -1;
        }
        else if (inputString[i] == ']') {
            if (!box3.empty()) {
                box3.pop();
                answer++;
            }
            else return -1;
        }
        else if (inputString[i] == '>') {
            if (!box4.empty()) {
                box4.pop();
                answer++;
            }
            else return -1;
        }
    }
    return answer;
}