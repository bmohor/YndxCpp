#include <iostream>
#include <vector>
#include <string>
using namespace std;

void	switchNext(vector<vector<string>>& day, int& month) {
	month++;
	if (month == 8)
		return ;
	if (month == 13) {
		month = 1;
		return ;
	}
	if (month == 2) {
		for (int i = 28; i < 31; i++) {
			for (auto j : day[i])
				day[27].push_back(j);
		}
		day.resize(28);
		return ;
	}
	if (day.size() != 31) {
		day.resize(31);
	} else {
		for (auto j : day[30])
			day[29].push_back(j);
		day.resize(30);
	}
	
}

int main() {
	int month = 1;
	int numOfPlans, comms, i;
	string comma, plan;

	cin >> comms;
	if (comms > 0) {
		vector<vector <string>> day(31);
		while (comms--) {
			cin >> comma;
			if (comma == "ADD") {
	 			cin >> i >> plan;
				day[i - 1].push_back(plan);
			} else if (comma == "DUMP") {
				cin >> i;
				cout << day[i - 1].size();
				for (auto j : day[i - 1])
					cout << ' ' << j;
				cout << endl;
			}
			else if (comma == "NEXT")
				switchNext(day, month);
		}
	}
	return 0;
}
