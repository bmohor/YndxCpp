#include <iostream>
#include <exception>
using namespace std;

class Rational {
	public:
		Rational() {
			num = 0;
			den = 1;
		}
		Rational(int numerator, int denominator) {
			if (denominator == 0)
				throw invalid_argument("Denominator can't be zero");
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

Rational	operator/(Rational x, Rational y) {
	int resx = x.Numerator() * y.Denominator();
	int resy = x.Denominator() * y.Numerator();
	if (resy == 0)
		throw domain_error("Denominator can't be zero");
	return {resx, resy};
}



int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
