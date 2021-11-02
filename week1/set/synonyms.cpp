#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string comma, word1, word2;
	int N;

	cin >> N;
	map<string, set<string>> synonyms;
	while (N--) {
		cin >> comma;
		if (comma == "ADD") {
			cin >> word1 >> word2;
			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);
		} else if (comma == "COUNT") {
			cin >> word1;
			if (synonyms.count(word1) > 0)
				cout << synonyms[word1].size() << endl;
			else
				cout << '0' << endl;
		} else if (comma == "CHECK") {
			cin >> word1 >> word2;
			if (synonyms.count(word1) == 0) {
				cout << "NO" << endl;
				continue ;
			} else if (synonyms[word1].count(word2) > 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		
	}
}
