// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

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
    return 0;
}