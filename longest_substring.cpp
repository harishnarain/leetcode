#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
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
}