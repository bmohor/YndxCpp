#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int N;
	string capital, country, comma, new_country_name;
	map<string, string> countries;
	cin >> N;
	while (N--) {
		cin >> comma;
		if (comma == "CHANGE_CAPITAL") {
			cin >> country >> capital;
			auto search = countries.find(country);
			if (country != search->first)
				cout << "Introduce new country " << country << " with capital " << capital << endl;
			else if (capital == search->second)
				cout << "Country " << country << " hasn't changed its capital" << endl;
			else 
				cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << capital << endl;
			countries[country] = capital;
		} else if (comma == "RENAME") {
			cin >> country >> new_country_name;
			if (country == new_country_name || !countries.count(country) || countries.count(new_country_name)) {
				cout << "Incorrect rename, skip" << endl;
				continue ;
			}
			countries[new_country_name] = countries[country];
			cout << "Country " << country << " with capital "
				<< countries[country] << " has been renamed to " << new_country_name << endl;
			countries.erase(country);
		} else if (comma == "ABOUT") {
			cin >> country;
			if (countries.count(country))
				cout << "Country " << country << " has capital " << countries[country] << endl;
			else
				cout << "Country " << country << " doesn't exist" << endl;
		} else if (comma == "DUMP") {
			if (countries.size() == 0)
				cout << "There are no countries in the world" << endl;
			for (const auto& outpt : countries)
				cout << outpt.first << '/' << outpt.second << ' ';
			cout << endl;
		}
	}
}
