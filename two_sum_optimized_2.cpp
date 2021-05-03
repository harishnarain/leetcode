#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printArray(vector<int> &array)
{
    for (auto i : array)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

vector<int> twoSum(vector<int> &array, int targetSum)
{
    sort(array.begin(), array.end());
    printArray(array);
    int left = 0;
    int right = array.size() - 1;

    while (left < right)
    {
        if (array[left] + array[right] == targetSum)
            return {array[left], array[right]};
        else if (array[left] + array[right] < targetSum)
            left++;
        else if (array[left] + array[right] > targetSum)
            right--;
    }

    return {};
}

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
