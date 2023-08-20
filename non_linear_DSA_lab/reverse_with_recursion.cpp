#include <iostream>
using namespace std;
int reverseWithRecursion(int num, int reverseWithRecursion = 0)
{
    if (num == 0)
    {
        return reverseWithRecursion;
    }
    else
    {
        int remainder = num % 10;
        int reverse = reverse * 10 + remainder;
        num = num / 10;
        return reverseWithRecursion;
    }
}
int main()
{
    int userInput;
    cout << "Enter an integer number:";
    cin >> userInput;

    int reverseNumWithRecursion = reverseWithRecursion(userInput);
    cout << "Reverse with recursion is: " << reverseWithRecursion << endl;
}