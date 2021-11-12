#include <iostream>
using namespace std;

class Rational {
	public:
		Rational() {
			int num;
			int den;
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
		int	Numerator() {
			return num;
		}
		int	Denominator() {
			return den;
		}
	private:
		int num;
		int den;
		
};

Rational	operator+(Rational& x, Rational& y) {
	int resx, resy;
	if (y.Denominator() == x.Denominator()) {
		resx = y.Numerator() + x.Numerator();
		resy = x.Denominator();
	} else {
		resx = x.Numerator() * y.Denominator() + y.Numerator() * x.Denominator();
		resy = x.Denominator() * y.Denominator();
	}
	Rational res(resx, resy);
	return (res);
}

bool	operator==(Rational x, Rational y) {
	return (y.Denominator() == x.Denominator() && y.Numerator() == x.Numerator());
}


Rational	operator-(Rational& x, Rational& y) {
	int resx, resy;
	if (y.Denominator() == x.Denominator()) {
		resx = y.Numerator() - x.Numerator();
		resy = x.Denominator();
	} else {
		resx = x.Numerator() * y.Denominator() - y.Numerator() * x.Denominator();
		resy = x.Denominator() * y.Denominator();
	}
	Rational res(resx, resy);
	return (res);
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
