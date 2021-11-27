#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string stop;
	int N, count;
	int num = 1;

	cin >> N;
	map<int, set<string>> buses;
	map<set<string>, int> routes;
	while (N--) {
		cin >> count;
		set<string> tmp;
		for (int i = 0; i < count; i++) {
			cin >> stop;
			tmp.insert(stop);
		}	
		if (routes.count(tmp) > 0) {
			for (const auto& i : buses) {
				if (i.second == tmp)
					cout << "Already exists for " << i.first << endl;
			}
		} else {
			cout << "New bus " << num << endl;
			buses[num++] = tmp;
			routes[tmp] = count;
		}
		tmp.clear();
	}
	return (0);
}
