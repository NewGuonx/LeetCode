// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;

class Solution
{
  public:
    char findTheDifference(string s, string t)
    {
        int x[26] = {0}, y[26] = {0};
        for (int i = 0; i < s.size(); i++)
            x[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i++)
            y[t[i] - 'a']++;
        int i;
        for (i = 0; i < 26; i++)
            if (x[i] != y[i])
                break;
        return i + 'a';
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}