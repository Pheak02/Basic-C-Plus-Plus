#include <iostream>
using namespace std;
int main()
{
    //====FIRST WAY======
    // int i = 0;
    // for (i; i < 5; ++i)
    // {
    //     cout << i << " ";
    // }

    //====SECOND WAY======
    // for (int i; i < 5; ++i)
    // {
    //     cout << i << " ";
    // }

    /* =======SUM number==== */
    // int userInput;
    // int sum = 0;
    // for (int i = 0; i <= 5; i++)
    // {
    //     cout << "Enter a number: ";
    //     cin >> userInput;
    //     sum += userInput;
    // }
    // cout << "The sum of your number is:" << sum;

    /* RANGE BASED LOOP*/
    int num_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int n : num_array)
    {
        cout << n << " ";
    }
    return 0;
}