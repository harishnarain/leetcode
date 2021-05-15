#include <iostream>
#include <string>
using namespace std;

string convertToZigZag(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }

    int stringLength = s.length();
    bool down = true;

    int row = 0;
    string zigZagString[numRows];

    for (int i = 0; i < stringLength; i++)
    {
        zigZagString[row].push_back(s[i]);

        if (row == 0)
        {
            down = true;
        }

        if (row == numRows - 1)
        {
            down = false;
        }

        down ? row++ : row--;
    }

    string convertedString;

    for (int i = 0; i < numRows; i++)
    {
        convertedString.append(zigZagString[i]);
    }

    return convertedString;
}

int main()
{
    string inputString = "PAYPALISHIRING";
    int numOfRows = 3;
    cout << convertToZigZag(inputString, numOfRows) << '\n';
    return 0;
}