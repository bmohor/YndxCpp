#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int N;
	string word;
	set<string> res;
	
	cin >> N;
	while (N--) {
		cin >> word;
		res.insert(word);
	}
	cout << res.size() << endl;
	return (0);
}
