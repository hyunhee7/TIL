// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
#include <string>

using namespace std;


string solution(string& S, string& C) {
    string result = "";
    string name = "";
    string company = "";
    vector<string> id_list = { "" };
    vector<int>id_count = { 0 };

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != ';' && i != S.size() - 1) {
            name += S[i];
        }
        else {
            if (i == S.size() - 1) {
                name += S[S.size() - 1];
            }
            string first_name = "";
            string middle_name = "";
            string last_name = "";
            int cnt = 0;
            for (int j = 0; j < name.size(); j++) {
                if (name[j] == ' ') {
                    cnt++;
                    continue;
                }
                if (cnt == 0) {
                    last_name += name[j];
                }
                if (cnt == 1) {
                    middle_name += name[j];
                }
                if (cnt == 2) {
                    first_name += name[j];
                }
            }
            //cout << last_name <<" "<< middle_name <<" "<< first_name << endl;
            string ID = "";
            if (cnt == 1) {
                ID = middle_name + "_" + last_name;

            }
            else if (cnt == 2) {
                ID = first_name + "_" + last_name;
            }
            bool exist = false;

            for (int j = id_list.size() - 1; j >= 0; j--) {
                if (ID.compare(id_list[j]) == 0) {
                    id_list.push_back(ID);
                    id_count.push_back(id_count[j] + 1);
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                id_list.push_back(ID);
                id_count.push_back(1);
            }
            string mail;
            if (exist) {
                mail = ID + to_string(id_count[id_count.size() - 1]) + "@" + C + ".com";
            }
            else {
                mail = ID + "@" + C + ".com";
            }
            for (int j = 0; j < mail.size(); j++) {
                if (mail[j] >= 'A' && mail[j] <= 'Z') {
                    mail[j] -= 'A';
                    mail[j] += 'a';
                }
            }


            result += name + " <" + mail + ">; ";
            name = "";
            i += 1;
        }
    }
    /*cout << endl;
    for (int i = 1; i < id_list.size(); i++) {
       cout << id_list[i] << " " << id_count[i]<<endl;
    }*/
    string return_value = "";
    for (int i = 0; i < result.size() - 2; i++) {
        return_value += result[i];
    }
    return return_value;
}
int main() {
    string S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker", C = "Example";
    cout << solution(S, C) << endl;

    return 0;
}