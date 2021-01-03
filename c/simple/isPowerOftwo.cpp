// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (!n) return false;
        while (n)
        {
            if (n != 1 && n % 2 != 0)
                return false;
            n /= 2;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}