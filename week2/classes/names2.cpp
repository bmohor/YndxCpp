#include <map>
#include <string>
#include <vector>
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
				return (fname[fn] + " with unknown last name");
			else if (fn == -1)
				return (lname[ln] + " with unknown first name");
			return (fname[fn] + " " + lname[ln]);
		}
		string	GetFullNameWithHistory(int year) {
			string resF = "";
			int fn = findNearest(fname, year);
			if (fn > 0)
				concatMe(fname, fn, resF);
			string resL = "";
			int ln = findNearest(lname, year);
			if (ln > 0)
				concatMe(lname, ln, resL);
			if (fn == -1 && ln == -1)
				return ("Incognito");
			if (ln == -1)
				return (resF + " with unknown last name");
			else if (fn == -1)
				return (resL + " with unknown first name");
			return (resF + " " + resL);
		}
	private:
		void	concatMe(map<int, string>& name, int fn, string& res) {
				vector<string> hist(0);
				gimmenames(name, fn, hist);
				res = name[fn];
				if (hist.size() > 0) {
					for (int i = 0; i < hist.size() - 1; i++) {
						if (hist[i] == hist[i + 1])
							hist.erase(hist.begin() + i);
					}
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
		void	gimmenames(map<int, string>& tmp, int year, vector<string>& v) {
			year--;
			int i = findNearest(tmp, year);
			if (i != -1) {
				v.push_back(tmp[i]);
				gimmenames(tmp, i, v);
			}
		}
		int	findNearest(const map<int, string>& tmp, int year) {
			int res = -1;
			for (const auto& i : tmp) {
				if (i.first <= year)
					res = i.first;
				if (i.first > year)
					break ;
			}
			return (res);
		}
		map<int, string> fname;
		map<int, string> lname;
};
