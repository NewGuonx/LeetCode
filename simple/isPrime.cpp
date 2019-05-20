// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 3)
            return 0;
        int cnt = 1;
        for (int i = 3; i < n; i++)
            if (isprime(i))
                cnt++;
        return cnt;
    }
    inline bool isprime(int &num)
    {
        if (num % 2 == 0)
            return false;
        for (int i = 3; i <= sqrt(num); i += 2)
            if (num % i == 0)
                return false;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int prime[100001];
    memset(prime, 1, 100001);
    for (int i = 2; i * i < 100001; i++)
        for (int j = 2; j * i < 10001; j++)
            prime[i * j] = 0;
    prime[2] = 1, prime[3] = 1, prime[0] = 0, prime[1] = 0;
    return 0;
}