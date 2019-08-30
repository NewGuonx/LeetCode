// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    string toHex(int num)
    {
        if (num == 0) return "0";
        string hex = "0123456789abcdef", ans = "";
        while (num  && ans.size() < 8)
        {
            ans = hex[num & 0xf] + ans;
            num >>= 4;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();   
    return 0;
}