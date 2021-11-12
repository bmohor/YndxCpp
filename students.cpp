#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Student {
	string name;
	string lastname;
	int day;
	int month;
	int year;
};

int main() {
	int N;
	cin >> N;
	vector<Student> s;
	while (N--) {
		Student tmp;
		cin >> tmp.name >> tmp.lastname >> tmp.day >> tmp.month >> tmp.year;
		s.push_back(tmp);
	}
	int request, id;
	string comma;
	cin >> request;
	while (request--) {
		cin >> comma;
		cin >> id;
		id--;
		if (id > s.size())
			cout << "bad request" << endl;
		else if (comma == "name")
			cout << s[id].name << ' ' << s[id].lastname << endl;
		else if (comma == "date")
			cout << s[id].day << '.' << s[id].month << '.' << s[id].year << endl;
		else
			cout << "bad request" << endl;
	}
	return 0;
}
