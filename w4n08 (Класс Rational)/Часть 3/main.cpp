#include <iostream>
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

int main()
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal)
        {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal)
        {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}