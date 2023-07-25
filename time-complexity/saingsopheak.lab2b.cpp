#include <iostream>
//effecient implementation
int sumFast(int n)
{
    int sum = (n * (n + 1)) / 2;
    return sum;
}

int main()
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    int result = sumFast(n);
    std::cout << " sum of 1 + 2 + ... + " << n << " is: " << result << std::endl;

    return 0;
}