#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int myAtoi(string s)
{
    // Check if string is null
    if (s.length() == 0)
        return 0;

    // Initialize left cursor
    int left = 0;

    // Trim whitespace
    while (s[left] == ' ')
        left++;

    // Keep record of negative or positive and advance left cursor
    bool negative = false;
    if (s[left] == '-')
        negative = true, left++;
    else if (s[left] == '+')
        left++;

    // Generate result int from int substring
    double result = 0;
    while ((s[left] >= 48 && s[left] <= 57) && (left < s.length()))
    {
        result *= 10;
        result += s[left] - 48;
        if (result >= pow(2, 31) && negative)
            return INT_MIN;
        if (result >= INT_MAX && !negative)
            return INT_MAX;
        left++;
    }

    if (!result)
        return 0;
    return negative ? result * -1 : result;
}

int main()
{
    cout << myAtoi("-123") << '\n';
    cout << myAtoi("0") << '\n';
    cout << myAtoi("1") << '\n';
    cout << myAtoi("156") << '\n';
    cout << myAtoi("     -42") << '\n';
    cout << myAtoi("4193 with words") << '\n';
    cout << myAtoi("words and 987") << '\n';
    cout << myAtoi("00000032") << '\n';
    cout << myAtoi("00000-32") << '\n';
    cout << myAtoi("-91283472332") << '\n';
    cout << myAtoi("+1") << '\n';
    cout << myAtoi("++12") << '\n';
    cout << myAtoi("+-12") << '\n';
    cout << myAtoi("-+12") << '\n';
    cout << myAtoi("--12") << '\n';
    cout << myAtoi("000-000-12") << '\n';
    cout << myAtoi("00000-42a1234") << '\n';
    cout << myAtoi("-2147483647") << '\n';
    return 0;
}