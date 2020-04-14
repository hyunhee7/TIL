#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;
    map< string, string > m;
    set<string> s;
    for (int i = 0; i < dataSource.size();i++) {
        for (int j = 1; j < dataSource[i].size(); j++) {
            m.insert(make_pair(dataSource[i][0], dataSource[i][j]));
        }
    }
    
    for (int i = 0; i < tags.size; i++) {
        map<string, string>::iterator it = m.find(tags[i]);
        it = m.find(tags[i]);
        if (it == m.end()) {
            continue;
        }
        else {
            s.insert(it->first);
        }
    }
    //정렬
    /*set<string>::iterator it2;
    for (it2 = s.begin(); it2 != s.end(); ++it) {

    }*/
    //10개만 answer넣기
    return answer;
}
int main() {
    vector<vector<string>> dataSource, vector<string> tags;
    vector<string> answer = solution(dataSource, tags);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

}