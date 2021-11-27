#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n, i, res = 0;
	string s;
	cin >> n;
	vector<bool> people;

	while (n--) {
		cin >> s;
		if (s == "WORRY_COUNT") {
			for (bool i : people) {
				if (i == true)
					res += 1;
			}
			cout << res << endl;
			res = 0;
			continue ;
		}
		cin >> i;
		if (s == "WORRY")
			people[i] = true;
		else if (s == "QUIET")
			people[i] = false;
		else if (s == "COME" && i > 0) {
			while (i--)
				people.push_back(false);
		}
		else if (s == "COME" && i < 0)
			people.erase(people.end() + i, people.end());
	}
}
