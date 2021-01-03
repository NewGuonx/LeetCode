// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int titleToNumber(string s)
    {
        int num = 0;
        std::reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            num += pow(26, i) * (s[i] - 'A' + 1);
        }
        return num;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}