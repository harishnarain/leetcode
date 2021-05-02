#include <iostream>
using namespace std;

void count(int start, int end)
{
    int &i = start;
    cout << i << '\n';
    i++;

    if (i <= end)
    {
        count(i, end);
    }
}

int main()
{
    count(1, 10);
    return 0;
}