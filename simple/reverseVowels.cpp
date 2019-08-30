// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    string reverseVowels(string s)
    {
       unordered_map<char,int> vowel;
       vowel['a'] = 1, vowel['e'] = 1, vowel['i'] = 1, vowel['o'] = 1, vowel['u'] = 1, vowel['A'] = 1, vowel['E'] = 1, vowel['I'] = 1, vowel['O'] = 1, vowel['U'] = 1;
       int pre = -1, post = -1;
       for (int i = 0, j = s.size() - 1; i < j;)
       {
           if (vowel.count(s[i]))
               pre = i;
           if (vowel.count(s[j]))
               post = j;
           if (pre != -1 && post != -1)
           {
               swap(s[pre], s[post]);
               pre = -1;
               post = -1;
           }
           if (pre == -1)
               i++;
           if (post == -1)
               j--;
        }
        return s;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.reverseVowels("leetcode");
    return 0;
}