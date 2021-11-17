#include <iostream>
#include <sstream>
using namespace std;

class Rational {
	public:
		Rational() {
			num = 0;
			den = 1;
		}
		Rational(int numerator, int denominator) {
			num = numerator;
			den = denominator;
			while (numerator > 0 && denominator > 0) {
				if (numerator > denominator)
					numerator %= denominator;
				else
					denominator %= numerator;
			}
			int same = denominator + numerator;
			num /= same;
			den /= same;
		}
		int Numerator() {
			return num;
		}
		int Denominator() {
			return den;
		}
	private:
		int num;
		int den;
};

bool	operator==(Rational x, Rational y) {
	return ((x.Numerator() == y.Numerator()) && (x.Denominator() == y.Denominator()));
}

ostream& operator<<(ostream& stream, Rational x) {
	stream << x.Numerator() << '/' << x.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& x) {
	if (!stream)
		return stream;
	char c;
	int xx, yy;
	stream >> xx;
	stream >> c;
	if (c != '/') {
		stream >> yy;
		return stream;
	}
	stream >> yy;
	if (!stream)
		return stream;
	Rational y(xx, yy);
	x = y;
	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }
    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }
    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;
	    return 6;
	}
    }
    cout << "OK" << endl;
    return 0;
}
