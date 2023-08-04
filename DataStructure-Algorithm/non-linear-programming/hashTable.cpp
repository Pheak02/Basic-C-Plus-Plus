#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> fruiteType;
    fruiteType["apple"] = 5;
    fruiteType["banana"] = 3;
    fruiteType["grape"] = 7;

    // access print value
    cout << "Value of 'apple':" << fruiteType["apple"] << endl;
    cout << "Value of 'banana':" << fruiteType["banana"] << endl;
    cout << "Value of 'grape':" << fruiteType["grape"] << endl;
    if (fruiteType.count("orange"))
    {
        cout << "Value of 'orange':" << fruiteType["orange"] << endl;
    }
    else
    {
        cout << "'Orange is not found in the hash table'" << endl;
    }
}