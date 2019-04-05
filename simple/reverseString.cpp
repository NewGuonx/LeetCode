// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    void reverseString(vector<char> &s)
    {
        for(int i = 0, j= s.size()-1; i < j; i++,j--)
            swap(s[i], s[j]);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}