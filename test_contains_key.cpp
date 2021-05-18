#include <iostream>
#include <unordered_map>
using namespace std;

void checkKey(unordered_map<int, string> map, int key)
{
    (map.find(key) != map.end()) ? cout << "Key found" << '\n' : cout << "Key missing" << '\n';
}

int main()
{
    unordered_map<int, string> map;

    map[10] = "Geeks";
    map[15] = "4";
    map[20] = "Geeks";

    checkKey(map, 20);
    checkKey(map, 5);

    return 0;
}