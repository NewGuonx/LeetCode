// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool isPowerOfFour(int n)
    {
        if(n < 1)return false;
        while(n){
            if(n % 4 != 0 && n != 1)
                return false;
            n /= 4;
        }
        return true;
    }
};


int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.isPowerOfThree(16);
    return 0;
}