#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Person {
	public:
		void	ChangeFirstName(int year, const string& name) {
			fname[year] = name;
		}
		void	ChangeLastName(int year, const string& lastname) {
			lname[year] = lastname;
		}
		string	GetFullName(int year) {
			int fn = findNearest(fname, year);
			int ln = findNearest(lname, year);
			if (fn == -1 && ln == -1)
				return ("Incognito");
			if (ln == -1)
				return (fname[fn] + " with unknown first name");
			else if (fn == -1)
				return (lname[ln] + " with unknown last name");
			return (fname[fn] + " " + lname[ln]);
		}
	private:
		int	findNearest(const map<int, string>& tmp, int year) {
			int min = 0;
			for (const auto& i : tmp) {
				min = i.first;
				break;
			}
			for (int i = year; i >= min; i--) {
				if (tmp.count(i) > 0)
					return (i);
			}
			return (-1);
		}
		map<int, string> fname;
		map<int, string> lname;
};
