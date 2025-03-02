#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <map>

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
        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }
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

Rational operator*(const Rational &lhs, const Rational &rhs)
{
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs)
{
    if (rhs.Numerator() == 0)
    {
        throw domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

ostream &operator<<(ostream &out, const Rational &number)
{
    out << number.Numerator() << '/' << number.Denominator();
    return out;
}

istream &operator>>(istream &in, Rational &rational_number)
{
    int numerator, denominator;
    char separator;
    if (in.good())
    {
        in >> numerator >> separator >> denominator;
        if (in.good())
        {
            if (separator == '/')
            {
                rational_number = Rational(numerator, denominator);
            }
            else
            {
                in.setstate(ios_base::failbit);
            }
        }
    }
    return in;
}

bool operator==(const Rational &lhs, const Rational &rhs)
{
    if (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator())
    {
        return true;
    }
    return false;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    return ((lhs - rhs).Numerator() < 0);
}

int main()
{
    Rational first_number, second_number;
    char operation = ' ';
    try
    {
        cin >> first_number >> operation >> second_number;
        switch (operation)
        {
        case '+':
            cout << first_number + second_number << endl;
            break;
        case '-':
            cout << first_number - second_number << endl;
            break;
        case '*':
            cout << first_number * second_number << endl;
            break;
        case '/':
            cout << first_number / second_number << endl;
            break;
        default:
            cout << "incorrect operation" << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}