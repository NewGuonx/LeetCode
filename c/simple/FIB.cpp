// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0)
            return 0;
        if (N == 1 || N == 2)
            return 1;
        int a1 = 1, a2 = 1, lock = 0;
        for (int i = 2; i < N; i++)
        {
            if (!lock)
            {
                lock = 1;
                a1 = a1 + a2;
            }
            else if (lock)
            {
                lock = 0;
                a2 = a1 + a2;
            }
        }
        return lock ? a1 : a2;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.fib(5);
    return 0;
}