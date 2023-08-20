#include <iostream>
int power(double base, int exponent)
{
    int result = 1.0;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}
int main()
{
    double base;
    int exponent;
    std::cout << "enter the base:";
    std::cin >> base;

    std::cout << "Enter the exponent:";
    std::cin >> exponent;

    double result = power(base, exponent);
    std::cout << base << " raised to the power of " << exponent << " is: " << result << std::endl;
}
