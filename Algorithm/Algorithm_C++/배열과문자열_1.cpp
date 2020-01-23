#include <iostream>
#include <hash_map>
using namespace std;
bool alphabet[27];
bool isCheck(string line) {
	if (line.size() > 128) return false;
	for (int i = 0; i < line.size(); i++) {
		if (line[i]) {
			return false;
		}
		alphabet[line[i]]=true;
	}
	return true;
}
int main() {
	string line = "hello";
	cout<< isCheck(line);
}