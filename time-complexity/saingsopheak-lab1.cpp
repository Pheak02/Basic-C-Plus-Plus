#include <iostream>
using namespace std;
void timeConstant()
{
    string universeName = "Parallel Universe";
    cout << "Hello from external universe, to " << universeName << endl;
}
void logarithmicFunction(int n)
{
    cout << "Logarithmic time complexity — O(log n) : \t";
    for (int i = 1; i < n; i *= 2)
    {
        cout << i << ",\t";
    }
}

int main()
{
    int n = 3;
    timeConstant();
    logarithmicFunction(n);
    return 0;
}