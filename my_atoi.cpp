#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool validChar(char c)
{
    // convert to char to int
    int convertedToAscii = (int)c;
    if (convertedToAscii == 45 || convertedToAscii == 43)
        return true;
    if (convertedToAscii >= 48 && convertedToAscii <= 57)
        return true;

    return false;
}

int myAtoi(string s)
{
    int left = 0;
    int right = 0;
    string intSubstring = "";

    // Check if string is null
    if (s.empty() || s.length() < 1)
        return 0;

    // Check for leading non-digit, non-whitespace or non-negative
    if (!validChar(s[0]) && s[0] != ' ')
        return 0;

    // Remove leading zeros or negatives with zeros
    while (s.length() > 1 && s[left] == '0' || s[left] == '-' && s[left + 1] == '0')
        left++;

    // Determine start of int substring
    while (!validChar(s[left]))
        left++;

    // Determine length of int substring
    right = left;
    while (validChar(s[right]))
        right++;
    int intSubstringLength = right - left;

    // Generate int substring
    intSubstring = s.substr(left, intSubstringLength);

    // Check for subsequent positives or negatives
    if ((intSubstring[0] == '-' || intSubstring[0] == '+') && (intSubstring[1] == '-' || intSubstring[1] == '+'))
        return 0;

    // Keep record of negative or positive and remove from int substring
    bool negative = false;
    if (intSubstring[0] == '-')
    {
        negative = true;
        intSubstring = intSubstring.replace(0, 1, "");
    }

    if (intSubstring[0] == '+')
    {
        intSubstring = intSubstring.replace(0, 1, "");
    }

    // Generate result int from int substring
    int result = 0;
    for (int i = intSubstring.length() - 1; i >= 0; i--)
    {
        if ((result + (intSubstring[i] - 48) * pow(10, (intSubstring.length() - (i + 1)))) > INT_MAX)
        {
            if (negative)
            {
                result = abs(INT_MIN);
            }
            else
            {
                result = INT_MAX;
            }
            break;
        }
        else
        {
            result += ((intSubstring[i] - 48) * pow(10, (intSubstring.length() - (i + 1))));
        }
    }

    // Apply negative if applicable
    if (negative)
    {
        result = -abs(result);
    }

    return result;
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
    return 0;
}