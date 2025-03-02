#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Image
{
    double quality;
    double freshness;
    double rating;
};

struct Params
{
    double a;
    double b;
    double c;
};

class FunctionPart
{
public:
    FunctionPart(char new_sign, double new_value)
    {
        sign = new_sign;
        value = new_value;
    }
    void Invert()
    {
        if (sign == '+')
        {
            sign = '-';
        }
        else if (sign == '-')
        {
            sign = '+';
        }
        else if (sign == '*')
        {
            sign = '/';
        }
        else if (sign == '/')
        {
            sign = '*';
        }
    }
    double Apply(double source) const
    {
        if (sign == '+')
        {
            return source + value;
        }
        else if (sign == '-')
        {
            return source - value;
        }
        else if (sign == '*')
        {
            return source * value;
        }
        else
        {
            return source / value;
        }
    }

private:
    char sign;
    double value;
};

class Function
{
public:
    void AddPart(char operation, double value)
    {
        func.push_back({operation, value});
    }
    void Invert()
    {
        for (auto &item : func)
        {
            item.Invert();
        }
        reverse(begin(func), end(func));
    }
    double Apply(double value)
    {
        for (const auto &item : func)
        {
            value = item.Apply(value);
        }
        return value;
    }

private:
    vector<FunctionPart> func;
};

Function MakeWeightFunction(const Params &params,
                            const Image &image)
{
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params &params, const Image &image)
{
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params,
                              const Image &image,
                              double weight)
{
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main()
{
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}