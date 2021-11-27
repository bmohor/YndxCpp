#include<map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main() {
	string station;
	int N, n;
	int num = 1;
	int count = 1;

	cin >> N;
	map<vector<string>, int> route;
	map<int, vector<string>> buses;
	while (N--) {
		vector<string> tmp;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> station;
			tmp.push_back(station);	
		}
		if (route.count(tmp) > 0) {
			for(const auto& i : buses) {
				if (i.second == tmp) {
					cout << "Already exists for " << count << endl;
					count = 1;
					break ;
				}
				count++;
			}
		}
		else {
			cout << "New bus " << num << endl;
			buses[num++] = tmp;
			route[tmp] = n;
		}
		tmp.clear();	
	}
	return (0);
}
