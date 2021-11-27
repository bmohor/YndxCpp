#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int zer = 0;
	int N, num;
	vector<int> nums;

	cin >> N;
	while(N--) {
		cin >> num;
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), [](int a, int b) {return (abs(a) < abs(b));});
	for (auto& i : nums)
		cout << i << ' ';
	cout << endl;
	return (0);
}
