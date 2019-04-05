// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        if(n < 1)return false;
        while(n){
            if(n % 3 != 0 && n != 1)
                return false;
            n /= 3;
        }
        return true;
    }
};

class Solution1
{
  public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1162261467 % n == 0;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.isPowerOfThree(15);
    return 0;
}