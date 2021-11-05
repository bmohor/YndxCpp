#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int N;
	string word;
	vector<string> words;

	cin >> N;
	while (N--) {
		cin >> word;
		words.push_back(word);
	}
	sort(begin(words), end(words), [](string a, string b){
		for (int i = 0; a[i]; i++)
			a[i] = tolower(a[i]);
		for (int i = 0; b[i]; i++)
			b[i] = tolower(b[i]);
		return (a < b);
	});
	for (const auto& i : words)
		cout << i << ' ';
	cout << endl;
	return (0);
}
