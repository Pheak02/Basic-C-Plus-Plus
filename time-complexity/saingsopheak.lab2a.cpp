#include <iostream>
//inefficient implementation
int sumSlow(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            sum += j;
        }
    }
    return sum;
}

int main()
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    int result = sumSlow(n);
    std::cout << "The sum of 1 + 2 + ... + " << n << " is: " << result << std::endl;

    return 0;
}