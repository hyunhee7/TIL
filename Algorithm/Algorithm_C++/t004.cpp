//#include <string>
//#include <vector>
//#include <iostream>
//#include <cstdlib>
//#include <algorithm>
//using namespace std;
//bool isFin[100001];
//vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
//    for (int i = 0; i < transactions.size(); i++) {
//        int index = transactions[i][0][0] - '0';
//        if (!isFin[index]) {
//            //예금
//            string acc_id = transactions[i][2];
//            isFin[index] = true;
//            if (transactions[i][1] == "SAVE") {
//                bool isExist = false;
//                for (int j = 0; j < snapshots.size(); j++) {
//                    if (acc_id == snapshots[j][0]) {
//                        int now = stoi(snapshots[j][1]) + stoi(transactions[i][3]);
//                        snapshots[j][1] = to_string(now);
//                        isExist = true;
//                    }
//                }
//                if (!isExist) {
//                    snapshots.push_back({ acc_id, transactions[i][3] });
//                }
//            }
//            //출금
//            else {
//                for (int j = 0; j < snapshots.size(); j++) {
//                    if (acc_id == snapshots[j][0]) {
//                        int now = stoi(snapshots[j][1]) - stoi(transactions[i][3]);
//                        snapshots[j][1] = to_string(now);
//                    }
//                }
//            }
//        }
//    }
//    sort(snapshots.begin(), snapshots.end());
//    return snapshots;
//}
//
//int main() {
//    vector<vector<string>> snapshots = {{"ACCOUNT2", "100"},
//                                        {"ACCOUNT1", "150"} };
//    vector<vector<string>> transactions = { {"1", "SAVE", "ACCOUNT2", "100"} ,
//                                            {"2", "WITHDRAW", "ACCOUNT1", "50" },
//                                            {"1", "SAVE", "ACCOUNT2", "100"},
//                                            {"4", "SAVE", "ACCOUNT3", "500"},
//                                            {"3", "WITHDRAW", "ACCOUNT2", "30"}
//                                           };
//    vector<vector<string>> answer = solution(snapshots, transactions);
//    for (int i = 0; i < answer.size(); i++) {
//        for (int j = 0; j < answer[0].size(); j++) {
//            cout << answer[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//}