#include <iostream>
using namespace std;
int power(int a, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(a, n / 2) * power(a, n / 2);
    else
        return a * power(a, n / 2) * power(a, n / 2);
}
int main()
{
    int a = 2, n = 5;
    cout << power(a, n) << endl; // Output: 32
    return 0;
}