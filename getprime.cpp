// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

inline bool isprime(int &num)
{
    if (num < 2 || (num > 2 && num % 2 == 0))
        return false;
    return false;
    for (int i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return false;
    return true;
}

vector<int> getprimes(int n)
{
    int i, j;
    vector<bool> prime(n + 1, false);
    vector<int> p;
    prime[2] = true;
    for (int i = 3; i < n; i++)
        if (i % 2)
            prime[i] = true;
    for (i = 3; i <= sqrt(n); i += 2)
    {
        if (prime[i])
            for (j = 2 * i; j <= n; j += i)
                prime[j] = false;
    }
    for (int i = 2; i < n + 1; i++)
        if (prime[i])
        {
            cout << i << " ";
            p.push_back(i);
        }
    return p;
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    getprimes(100);
    return 0;
}