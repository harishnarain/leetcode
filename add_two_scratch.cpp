#include <iostream>
#include <vector>
using namespace std;

vector<int> addTwo(int *l1, int *l2)
{
    vector<int> result;
    bool carrier = false;

    for (int i = 0; i < 3; i++)
    {
        int tempSum = l1[i] + l2[i];

        if (carrier)
        {
            tempSum += 1;
        }

        if (tempSum >= 10)
        {
            carrier = true;

            if ((i + 1) != 3)
            {
                result.push_back(tempSum - 10);
            }
            else
            {
                result.push_back(tempSum - 10);
                result.push_back(1);
            }
        }
        else
        {
            carrier = false;
            result.push_back(tempSum);
        }
    }

    return result;
}

int main()
{
    int l1[] = {2, 4, 3};
    int l2[] = {5, 6, 4};

    vector<int> sol = addTwo(l1, l2);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << ' ';
    }
    cout << '\n';

    return 0;
}