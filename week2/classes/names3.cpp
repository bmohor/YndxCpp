#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int	findNearest(const map<int, string>& tmp, int year, int yob) {
	int res = yob - 1;
	for (const auto& i : tmp) {
		if (i.first <= year)
			res = i.first;
		if (i.first > year)
			break ;
	}
	return (res);
}
	
void	gimmenames(map<int, string>& tmp, int year, vector<string>& v, int yearofbirth) {
	year--;
	int i = findNearest(tmp, year, yearofbirth);
	if (i >= yearofbirth) {
		if (v.size() == 0)
			v.push_back(tmp[i]);
		if (v.size() > 0 && v.back() != tmp[i])
			v.push_back(tmp[i]);
		gimmenames(tmp, i, v, yearofbirth);
	}
}

void	concatMe(map<int, string> name, int fn, string& res, int yob) {
	vector<string> hist;
	gimmenames(name, fn, hist, yob);
	res = name[fn];
	if (hist.size() > 0) {
		if (hist.size() == 1) {
			if (hist[0] != res)
				res += " (" + hist[0] + ")";
			hist.clear();
		} else if (hist.size() > 1) {
			if (hist[0] == res)
				hist.erase(hist.begin());
			int HistSize = hist.size();
			res += " (";
			for (int i = 0; i < HistSize; i++) {
				if (i + 1 == HistSize) {
					res += hist[i] + ")";
					break ;
				}
				res += hist[i] + ", ";
			}
		hist.clear();
		}
	}
}

class Person {
	public:
		Person(const string& firstname, const string& lastname, int year) {
			fname[year] = firstname;
			lname[year] = lastname;
			yearofbirth = year;
		}
		void	ChangeFirstName(int year, const string& name) {
			if (year >= yearofbirth)
				fname[year] = name;
		}
		void	ChangeLastName(int year, const string& lastname) {
			if (year >= yearofbirth)
				lname[year] = lastname;
		}
		string	GetFullName(int year) const {
			int fn = findNearest(fname, year, yearofbirth);
			int ln = findNearest(lname, year, yearofbirth);
			map<int, string> fnm = fname;
			map<int, string> lnm = lname;

			if (fn < yearofbirth && ln < yearofbirth)
				return ("No person");
			return (fnm[fn] + " " + lnm[ln]);
		}
		string	GetFullNameWithHistory(int year) const {
			string resF = "";
			int fn = findNearest(fname, year, yearofbirth);
			if (fn >= yearofbirth)
				concatMe(fname, fn, resF, yearofbirth);
			string resL = "";
			int ln = findNearest(lname, year, yearofbirth);
			if (ln >= yearofbirth)
				concatMe(lname, ln, resL, yearofbirth);
			if (fn < yearofbirth && ln < yearofbirth)
				return ("No person");
			return (resF + " " + resL);
		}
		private:
		map<int, string>	fname;
		map<int, string>	lname;
		int			yearofbirth;
};
