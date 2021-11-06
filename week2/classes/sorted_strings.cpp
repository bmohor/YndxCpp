#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class SortedStrings{
	public:
		void	AddString(const string& str) {
			strs.push_back(str);
		}
		vector<string>	GetSortedStrings() {
			sort(begin(strs), end(strs));
			return (strs);
		}
	private:
		vector<string> strs;
};
