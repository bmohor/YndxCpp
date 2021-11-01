#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v) {
	vector<int> copy;
	int size = v.size() - 1;
	for (int i = size; i >= 0; i--)
		copy.push_back(v[i]);
	return (copy);
}
