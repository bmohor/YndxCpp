#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
    public:
	Rational() {
		num = 0;
		den = 1;
	}
	Rational(int numerator, int denominator) {
		int x = numerator;
		int y = denominator;
		while (x > 0 && y > 0) {
			if (x > y)
				x %= y;
			else
				y %= x;
		}
		int same = x + y;
		num = numerator / same;
		den = denominator / same;
	}
	int Numerator() const {
		return (num);
	}
	int Denominator() const {
		return (den);
	}
    private:
	int num;
	int den;

};

bool	operator==(Rational x, Rational y) {
	return ((x.Numerator() == y.Numerator()) && (x.Denominator() == y.Denominator()));
}

bool	operator<(Rational x, Rational y) {
	if (x.Denominator() == y.Denominator())
		return (x.Numerator() < y.Numerator());
	int resx = x.Numerator() * y.Denominator();
	int resy = y.Numerator() * x.Denominator();
	return (resx < resy);
	
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
