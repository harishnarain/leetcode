#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void printResult(bool result)
{
    result ? cout << "Matches" << '\n' : cout << "No match" << '\n';
}

bool search(string s, string p, unordered_map<string, bool> memo)
{
    cout << "In search...." << '\n';
    string state = s + '-' + p;
    if (memo.find(state) != memo.end())
        return memo[state];

    bool currentAnswer = false;

    if (p.empty())
        currentAnswer = s.empty();
    else
    {
        bool firstMatch = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if (p.length() >= 2 && p[1] == '*')
            currentAnswer = search(s, p.substr(2), memo) || (firstMatch && search(s.substr(1), p, memo));
        else
        {
            if (firstMatch)
                currentAnswer = search(s.substr(1), p.substr(1), memo);
        }
    }

    memo[state] = currentAnswer;
    return currentAnswer;
}

bool matchPattern(string s, string p)
{
    unordered_map<string, bool> memo;
    return search(s, p, memo);
}

int main()
{
    printResult(matchPattern("aa", "a"));                                 // false
    printResult(matchPattern("aa", "a*"));                                // true
    printResult(matchPattern("ab", ".*"));                                // true
    printResult(matchPattern("aab", "c*a*b"));                            // true
    printResult(matchPattern("mississippi", "mis*is*p*."));               // false
    printResult(matchPattern("boston", "boston"));                        // true
    printResult(matchPattern("aaa", "a*a"));                              // true
    printResult(matchPattern("aaa", "aaaa"));                             // false
    printResult(matchPattern("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c")); // false

    return 0;
}