#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int left = 0, right = 0;
    unordered_map<char, int> window;
    int longestStringLength = 0;

    while (right < s.size())
    {
        char c1 = s[right];
        window[c1]++;
        right++;

        while (window[c1] > 1)
        {
            char c2 = s[left];
            window[c2]--;
            left++;
        }
        longestStringLength = max(longestStringLength, right - left);
    }

    return longestStringLength;
}

int main()
{

    cout << lengthOfLongestSubstring("abcabcbb") << '\n'; // output 3

    cout << lengthOfLongestSubstring("bbbbb") << '\n'; // output 1

    cout << lengthOfLongestSubstring("pwwkew") << '\n'; // output 3

    cout << lengthOfLongestSubstring("") << '\n';

    cout << lengthOfLongestSubstring(" ") << '\n';

    cout << lengthOfLongestSubstring("ankle") << '\n';

    cout << lengthOfLongestSubstring("aab") << '\n';

    return 0;
}