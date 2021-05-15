#include <iostream>
#include <string>
using namespace std;

int reverse(int x)
{
    int reversedNumber = 0;

    while (x != 0)
    {
        int remainder = x % 10;
        if (reversedNumber > INT_MAX / 10 || reversedNumber < INT_MIN / 10)
            return 0; // Checking for overflow
        reversedNumber = (reversedNumber * 10) + remainder;
        x /= 10;
    }

    return reversedNumber;
}

int main()
{
    cout << reverse(8) << '\n';
    cout << reverse(123) << '\n';
    cout << reverse(120) << '\n';
    cout << reverse(-123) << '\n';
    cout << reverse(0) << '\n';
    cout << reverse(1534236469) << '\n';

    return 0;
}