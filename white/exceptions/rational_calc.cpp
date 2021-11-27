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
				throw invalid_argument("Invalid argument");
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

Rational	operator+(Rational x, Rational y) {
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


Rational	operator-(Rational x, Rational y) {
	int resx, resy;
	if (y.Denominator() == x.Denominator()) {
		resx = x.Numerator() - y.Numerator();
		resy = x.Denominator();
	} else {
		resx = x.Numerator() * y.Denominator() - y.Numerator() * x.Denominator();
		resy = x.Denominator() * y.Denominator();
	}
	Rational res(resx, resy);
	return (res);
}


Rational	operator/(Rational x, Rational y) {
	int resx = x.Numerator() * y.Denominator();
	int resy = x.Denominator() * y.Numerator();
	if (resy == 0)
		throw domain_error("Division by zero");
	return {resx, resy};
}

Rational	operator*(Rational x, Rational y) {
	int resx = x.Numerator() * y.Numerator();
	int resy = x.Denominator() * y.Denominator();
	return {resx, resy};
}

int main() {
	int x, y;
	char sign;
	cin >> x;
	cin.ignore(1);
	cin >> y;
	try {
		Rational first(x, y);
		cin >> sign;
		cin >> x;
		cin.ignore(1);
		cin >> y;
		Rational second(x, y);
		if (sign == '/') {
			Rational res = first / second;
			cout << res.Numerator() << '/' << res.Denominator() << endl;
		} else if (sign == '+') {
			Rational res = first + second;
			cout << res.Numerator() << '/' << res.Denominator() << endl;
		} else if (sign == '-') {
			Rational res = first - second;
			cout << res.Numerator() << '/' << res.Denominator() << endl;
		} else if (sign == '*') {
			Rational res = first * second;
			cout << res.Numerator() << '/' << res.Denominator() << endl;
		}
	} catch (exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
