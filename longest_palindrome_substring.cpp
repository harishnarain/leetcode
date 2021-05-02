#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int x, y, max = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (s[i] == s[j])
            {
                if (j - i == 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j] && j - i >= max)
            {
                max = j - i;
                x = i;
                y = j;
            }
        }
    }
    return s.substr(x, y - x + 1);
}

int main()
{
    cout << longestPalindrome("ggracecaradfs") << '\n';

    return 0;
}