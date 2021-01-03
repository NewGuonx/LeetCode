// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    bool Allupper(const string &word)
    {
        for (const auto &ch : word)
            if (islower(ch))
                return false;
        return true;
    }
    bool AllLower(const string &word)
    {
        for (int i = 1; i < word.size(); i++)
            if (isupper(word[i]))
                return false;
        return true;
    }
    bool detectCapitalUse(string word)
    {
        return AllLower(word) || Allupper(word);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}