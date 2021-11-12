#include <iostream>
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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
		cout << r.Numerator() << ' ' << r.Denominator() << endl;
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
