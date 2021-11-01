#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int midsum = 0;
	cin >> N;
	vector<int> days(N);
	vector<int> res;
	for (int i = 0; i < N; i++)
		cin >> days[i];
	for (int i : days)
		midsum += i;
	midsum /= N;
	for (int i = 0; i < N; i++) {
		if (days[i] > midsum)
			res.push_back(i);
	}
	cout << res.size() << endl;
	for (int i : res)
		cout << i << ' ';
	return (0);
}
