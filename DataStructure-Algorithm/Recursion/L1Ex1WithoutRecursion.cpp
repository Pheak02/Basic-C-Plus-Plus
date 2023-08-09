#include <iostream>
using namespace std;
int powerOfNum(int base, int exponent)
{
    int result = 1;
    while (exponent != 0)
    {
        if (exponent > 0)
        {
            result *= base;
            --exponent;
        }
        else
        {
            result /= base;
            ++exponent;
        }
    }
    return result;
}
int main()
{
    int base = 2, exponent = 3;
    cout << "The result of power of number is: " << powerOfNum(base, exponent);
    return 0;
}