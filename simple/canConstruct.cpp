// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int x[26] = {0};
        int y[26] = {0};
        for (auto &i : ransomNote)
            x[i - 'a']++;
        for (auto &i : magazine)
            y[i - 'a']++;
        for (int i = 0; i < 26; i++)
            if (x[i] > y[i])
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