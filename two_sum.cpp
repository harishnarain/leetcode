#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main()
{
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    // Output: Because nums[0] + nums[1] == 9, we return [0, 1].

    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]

    // Input: nums = [3,3], target = 6
    // Output: [0,1]

    vector<int> nums = {-1, -2, -3, -4, -5};
    int target = -8;

    vector<int> results = twoSum(nums, target);

    cout << results[0] << ", " << results[1] << '\n';
}

vector<int> twoSum(vector<int> &nums, int target)
{
    // Iterate through each element i
    // Iterate through each element after j
    // Check if sum matches target
    // return i and j

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
}
