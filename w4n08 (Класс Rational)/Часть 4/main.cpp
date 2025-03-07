#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>

using namespace std;

class Rational
{
public:
    Rational()
    {
        p = 0;
        q = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        if (numerator == 0)
        {
            denominator = 1;
        }
        int greatest_common_divisor = gcd(abs(numerator), abs(denominator));
        if (greatest_common_divisor)
        {
            numerator = numerator / greatest_common_divisor;
            denominator = denominator / greatest_common_divisor;
        }
        p = numerator;
        q = denominator;
    }
    int Numerator() const
    {
        return p;
    }
    int Denominator() const
    {
        return q;
    }

private:
    signed int p;
    unsigned int q;
};

Rational operator+(const Rational &lhs, const Rational &rhs)
{
    return Rational((lhs.Numerator() * rhs.Denominator()) + (rhs.Numerator() * lhs.Denominator()),
                    lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs)
{
    return Rational((lhs.Numerator() * rhs.Denominator()) - (rhs.Numerator() * lhs.Denominator()),
                    lhs.Denominator() * rhs.Denominator());
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    if ((lhs.Numerator() / lhs.Denominator()) == (rhs.Numerator() / rhs.Denominator()))
    {
        return true;
    }
    return false;
}

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream &operator<<(ostream &out, const Rational &number)
{
    out << number.Numerator() << '/' << number.Denominator();
    return out;
}

istream &operator>>(istream &in, Rational &number)
{

    if (!in.eof())
    {
        int new_p, new_q;
        in >> new_p;
        in.ignore(1);
        in >> new_q;
        number = {new_p, new_q};
    }
    return in;
}

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4")
        {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal)
        {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct)
        {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct)
        {
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
        if (!correct)
        {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    {
        istringstream input("2/4/6/8");
        Rational r1;
        input >> r1;
        bool correct = r1 == Rational(1, 2);
        if (!correct)
        {
            cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
            return 7;
        }
    }

    cout << "OK" << endl;
    return 0;
}