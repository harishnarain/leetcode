#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x)
{
    // Exclude negative numbers
    if (x < 0)
        return false;

    // Test for single digit
    if (x < 10 && x >= 0)
    {
        return true;
    }

    // Load int into a vector
    vector<int> testArr;
    while (x != 0)
    {
        testArr.push_back(x % 10);
        x /= 10;
    }

    // Test for palindrome
    int left = 0;
    int right = testArr.size() - 1;

    while (left < right)
    {
        if (testArr[left] != testArr[right])
            return false;

        left++, right--;
    }

    return true;
}

int main()
{
    int input;
    cout << "Please input a number: ";
    cin >> input;

    if (isPalindrome(input))
    {
        cout << input << " is a palindrome!" << '\n';
    }
    else
    {
        cout << input << " is NOT a palindrome!" << '\n';
    }

    return 0;
}