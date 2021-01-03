// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
  public:
    int guessNumber(int n)
    {
        int lo = 0, hi = n, mid;
        while (lo <= hi)
        {
            mid = lo +(hi-lo)/2;
            if (guess(mid) == 1)
                lo = mid + 1;
            else if (guess(mid) == -1)
                hi = mid - 1;
            else break;
        }
        return mid;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}