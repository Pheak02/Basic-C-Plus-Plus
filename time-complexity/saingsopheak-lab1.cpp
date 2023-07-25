#include <iostream>
using namespace std;
void constantFun()
// constant time complexity O(1)
{
    string universeName = "Parallel Universe";
    cout << "Hello from external universe, to " << universeName << endl;
}
void logarithmicFun(int n)
{
    cout << "Logarithmic time complexity — O(log n) : \t";
    for (int i = 1; i < n; i *= 2)
    {
        cout << i << ",\t";
    }
}
void LinearFun(int n)
{
    cout << "\nLinear time complexity — O(n) : \t";
    // because iterate n time(s)
    for (int i = 0; i < n; i++)
    {
        cout << i << ", ";
    }
}
void quadraticFun(int n)
{
    cout << "\nQuadratic time complexity — O(n^2) : \n";

    for (int i = 0; i < n; i++)
    { // O(n)
        for (int j = 0; j < n; j++)
        { // O(n)
            cout << "i: " << i << ", j: " << j << endl;
        }
    }
}
void linearTimeComplexity(int n, int m)
// Linear time — O(n + m)
{
    cout << "\nLinear time complexity — O(n+m) : \n";

    // Loop with 'n' iterations
    for (int i = 0; i < n; i++)
    {
        cout << "Iteration: " << i << endl;
    }

    // Loop with 'm' iterations
    for (int j = 0; j < m; j++)
    {
        cout << "Iteration: " << j << endl;
    }
}

int main()
{
    int n = 3, m = 4;
    constantFun();
    logarithmicFun(n);
    LinearFun(n);
    quadraticFun(n);
    linearTimeComplexity(n, m);
    return 0;
}
