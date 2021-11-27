#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void	newBus(map<int, map<string, vector<string>>>& order, int& id) {
	int stopNum;
	map<string, vector<string>> m;
	string bus, stop;

	cin >> bus >> stopNum;
	while (stopNum--) {
		cin >> stop;
		m[bus].push_back(stop);
	}
	order[id] = m;
	id++;
}

void	busesForStop(map<int, map<string, vector<string>>>& order, string stop, string bus) {
	int flag = 0;

	for (const auto& i : order) {
		for (const auto& j : i.second) {
			for (const auto& k : j.second) {
				if (k == stop && bus == "\0") {
					cout << j.first << ' ';
					flag++;
				} 
				else if (k == stop && bus != j.first) {
					cout << j.first << ' ';
					flag++;
				}
			}
		}
	}
	if (flag == 0 && bus == "\0")
		cout << "No stop";
	else if (flag == 0)
		cout << "no interchange";
	cout << endl;
}

void	stopsForBus(map<int, map<string, vector<string>>>& order) {
	string	bus;
	
	cin >> bus;
	for (const auto& i : order) {
		if (i.second.count(bus) > 0) {
			for (const auto& k : i.second) {
				for (const auto& j : k.second) {
					cout << "Stop " << j << ": ";
					busesForStop(order, j, bus);
				}
			}
			return ;
		}
	}
	cout << "No bus" << endl;
}

void	print_buses(map<int, map<string, vector<string>>>& order) {
	map<string, vector<string>> forPrint;

	if (order.size() != 0) {
		for (const auto& i : order) {
			for (const auto& j : i.second)
				forPrint[j.first] = j.second;
		}
		for (const auto& k : forPrint) {
			cout << "Bus " << k.first << ":";
			for (const auto& l : k.second)
				cout << ' ' << l;
			cout << endl;
		}
	} else
		cout << "No buses" << endl;
}

int main () {
	string comma, stop;
	int N;
	int id = 1;

	cin >> N;
	map<int, map<string, vector<string>>> order;
	while (N--) {
		cin >> comma;
		if (comma == "NEW_BUS")
			newBus(order, id);
		else if (comma == "BUSES_FOR_STOP") {
			cin >> stop;
			busesForStop(order, stop, "\0");
		}
		else if (comma == "STOPS_FOR_BUS")
			stopsForBus(order);
		else if (comma == "ALL_BUSES")
			print_buses(order);
	}
	return (0);
}
