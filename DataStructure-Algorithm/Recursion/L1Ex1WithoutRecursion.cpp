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
    int base, exponent;
    cout << "Please enter the base: ";
    cin >> base;
    cout << "Please enter the exponent: ";
    cin >> exponent;
    cout << "The result of the power of" << base << "raised to the power of" << exponent << "is" << powerOfNum(base, exponent);
    return 0;
}