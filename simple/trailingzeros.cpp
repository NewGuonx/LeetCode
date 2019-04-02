// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
#define POW(x) (pow(5, x))
class Solution
{
  public:
    int trailingZeroes(int n)
    {
        int i = 0, ans = 0;
        while (POW(i) <= n)
            i++;
        for (int j = 1; j < i; j++)
            ans += n / POW(j);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}