#include <iostream>
using namespace std;
// SUM NUMBER BETWEEN M-N
int main()
{
    int m = 2, n = 4;
    int sum = 0;
    for (int i = m; i < n; i++)
    {
        sum += i;
    }
    cout << "Sum=" << sum;

} // namespace std;
