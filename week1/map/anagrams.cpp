#include<map>
#include<iostream>
using namespace std;
void	checkItOutFool(string a, string b) {
	map<char, int> m1;
	map<char, int> m2;
	for (int i = 0; a[i]; i++)
		++m1[a[i]];
	for (int i = 0; b[i]; i++)
		++m2[b[i]];
	if (m1 == m2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int main() {
	string a, b;
	int N;
	cin >> N;
	while (N--) {
		cin >> a >> b;
		checkItOutFool(a, b);	
	}
}
