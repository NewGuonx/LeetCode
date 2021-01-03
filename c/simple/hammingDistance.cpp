// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int cnt;
        x ^= y;
        cnt = 0;
        while (x != 0)
        {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}