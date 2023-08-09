#include <iostream>
using namespace std;
// SUM NUMBER BETWEEN M-N
int recursive_sum(int m, int n)
{
    if (m == n)
        return m; // can either m or n cuz they're equal
    // the meaning here is recursion will stop and return m when m and n is equal

    // divide problem into smaller version
    return m + recursive_sum(m + 1, n); // refer to the else
}
int main()
{
    int m = 2, n = 4;
    cout << "Sum=" << recursive_sum(m, n);
    // without recursion
    //  int sum = 0;
    //  for (int i = m; i <= n; i++)
    //  {
    //      sum += i;
    //      cout << "Sum=" << sum << "\n";
    //  }
}
