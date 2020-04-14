//#include <string>
//#include <vector>
//#include <cmath>
//#include <iostream>
//using namespace std;
//
//int calc(int index, int sheet1, int sheet2, int n, vector<string> sheets, string answer_sheet) {
//    int val = 0;
//    int repeat = 0;
//    //cout << "sheet1:" << sheet1 << ", sheet2:" << sheet2 << endl;
//    int max_val = 0;
//    for (int i = index; i < n; i++) {
//        if (sheets[sheet1][i]-'0' == sheets[sheet2][i]-'0' && answer_sheet[i]-'0' != sheets[sheet1][i]-'0') {
//            //cout << "같은문항: " << i << endl;
//            val++;
//            repeat++;
//            if (i == n - 1) {
//                if (max_val < repeat)max_val = repeat;
//            }
//        }
//        else {
//            if (max_val < repeat)max_val = repeat;
//            repeat = 0;
//        }
//    }
//    int res = val + pow(max_val, 2);
//    //cout << "val: " << val << ", 연속: " << max_val << endl;
//    return res;
//}
//int solution(string answer_sheet, vector<string> sheets) {
//    int answer = 0;
//    int n = answer_sheet.size();
//
//    for (int i = 0; i < n; i++) {
//        int ans_num = answer_sheet[i]-'0';
//        for (int j = 0; j < sheets.size(); j++) {
//            int sheet_num = sheets[j][i] - '0';
//            if (ans_num != sheet_num) {
//                //cout << "ans_num:" << ans_num << " " << sheet_num << endl;
//                for (int k = j + 1; k < sheets.size(); k++) {
//                    if (sheet_num == sheets[k][i]-'0') {
//                        int res = calc(i, j, k, n, sheets, answer_sheet);
//                        //cout << i << " " << j << " " << k << " " << res << endl;
//                        if (res > answer) {
//                            answer = res;
//                        }
//                    }
//                }
//            }
//        }
//    }
//    return answer;
//}
//
//int main() {
//    string answer_sheet1 =  "4132315142";
//    vector<string> line = { "3241523133",
//                            "4121314445",
//                            "3243523133",
//                            "4433325251",
//                            "2412313253" };
//    string answer_sheet2 = "53241";
//    vector<string> line2 = { "53241", "42133", "53241", "14354" };
//
//    string answer_sheet3 = "24551";
//    vector<string> line3 = { "24553", "24553", "24553", "24553" };
//    int answer = solution(answer_sheet3, line3);
//    cout << answer << endl;
//
//}