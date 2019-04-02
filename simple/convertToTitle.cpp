// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    string convertToTitle(int n)
    {
        string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;
        int c;
        while (n)
        {
            c = (n - 1) % 26;
            n = (n - 1) / 26;
            res.push_back(s[c]);
        }
        ::reverse(res.begin(), res.end());
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}