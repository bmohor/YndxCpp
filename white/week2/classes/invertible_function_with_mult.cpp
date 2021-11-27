#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Function {
	public :
		void	AddPart(char s, double value) {
			operations.push_back(value);
			sign.push_back(s);
		}
		double 	Apply(double value) const{
			int s = sign.size();
			for (int i = 0; i < s; i++) {
				if (sign[i] == '+')
					value += operations[i];
				else if (sign[i] == '-')
					value -= operations[i];
				else if (sign[i] == '*')
					value *= operations[i];
				else
					value /= operations[i];
			}
			return value;
		}
		void	Invert() {
			reverse(sign.begin(), sign.end());
			reverse(operations.begin(), operations.end());
			for (auto& i : sign) {
				if (i == '+')
					i = '-';
				else if (i == '-')
					i = '+';
				else if (i == '*')
					i = '/';
				else
					i = '*';
			}
		}
	private:
		vector<char>	sign;
		vector<double>	operations;
};

