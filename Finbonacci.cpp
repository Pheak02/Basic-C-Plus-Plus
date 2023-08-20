#include <iostream>
using namespace std;

int fibonacci(int target, int term1, int term2);

int main()
{
    cout << fibonacci(20, 0, 1);
}
int fibonacci(int target, int term1, int term2)
{
    cout << term1 << " ";
    if (target == 0)
    {
        return term1 + term2;
    }
    else
    {
        fibonacci(target - 1, term2, term1 + term2);
    }
}