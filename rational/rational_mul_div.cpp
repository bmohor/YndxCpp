#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
	    num = 0;
	    den = 1;
    }

    Rational(int numerator, int denominator) {
	int x = abs(numerator);
	int y = abs(denominator);
	while (x > 0 && y > 0) {
		if (x > y)
			x %= y;
		else
			y %= x;
	}
	int same = x + y;
	num = numerator / same;
	den = denominator / same;
	if (num < 0 && den < 0) {
		num = abs(num);
		den = abs(den);
	}
	if (den < 0) {
		num *= -1;
		den = abs(den);
	}
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

Rational	operator*(Rational x, Rational y) {
	int resx = x.Numerator() * y.Numerator();
	int resy = x.Denominator() * y.Denominator();
	return {resx, resy};
}

Rational	operator/(Rational x, Rational y) {
	int resx = x.Numerator() * y.Denominator();
	int resy = x.Denominator() * y.Numerator();
	return {resx, resy};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
