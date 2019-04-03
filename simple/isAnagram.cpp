// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        int i, x[26] = {0}, y[26] = {0};
        for (i = 0; i < s.size(); i++)
            x[s[i] - 'a']++;
        for (i = 0; i < t.size(); i++)
            y[t[i] - 'a']++;
        for (i = 0; i < 26; i++)
            if (x[i] != y[i])
                return false;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}