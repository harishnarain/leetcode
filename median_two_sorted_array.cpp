#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> mergedArray;

    // copy elements from first array
    for (int i = 0; i < nums1.size(); i++)
        mergedArray.push_back(nums1[i]);

    // copy elements from second array
    for (int i = 0; i < nums2.size(); i++)
        mergedArray.push_back(nums2[i]);

    // sort merged array
    sort(mergedArray.begin(), mergedArray.end());

    // determine median
    if (mergedArray.size() % 2 == 0)
    {
        double el1 = mergedArray[mergedArray.size() / 2];
        double el2 = mergedArray[(mergedArray.size() / 2) - 1];
        return (el1 + el2) / 2;
    }
    return double(mergedArray[mergedArray.size() / 2]);
}

int main()
{
    vector<int> nums1 = {1, 1}, nums2 = {1, 2};

    cout << fixed << setprecision(5);
    cout << findMedianSortedArrays(nums1, nums2) << '\n';

    return 0;
}