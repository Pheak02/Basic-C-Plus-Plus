#include <iostream>
using namespace std;
int reverseNumWithoutRecursion(int n)
{
    int reverse = 0;
    while (n != 0)
    {
        int remainder = n % 10; // remainderainder is last digit
        reverse = reverse * 10 + remainder;
        n /= 10; // to do iteration
    }
    return reverse; // return last reverse number
}
int reverseWithRecursion(int num, int rev)
{
    if (num == 0)
    {
        return rev;
    }
    int remainder = num % 10;
    rev = rev * 10 + remainder;
    return reverseWithRecursion(num / 10, rev);
}
int main()
{
    int userInput;
    cout << "Enter an integer number:";
    cin >> userInput;

    int reverseNumIteration = reverseNumWithoutRecursion(userInput);
    cout << "Reverse without recursion is: " << reverseNumIteration << endl;

    int reverseNumWithRecursion = reverseWithRecursion(userInput, 0);
    cout << "Reverse with recursion is: " << reverseNumWithRecursion << endl;
    return 0;
}