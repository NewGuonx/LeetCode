// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
// sliding window
class Solution
{
  public:
    vector<int> findAnagrams(string s, string p)
    {
        int ss = s.size(), ps = p.size();
        if (ss < ps) return {};
        vector<int> sh(26, 0), ph(26, 0), ans;
        for (int i = 0; i < ps; i++)
        {
            ph[p[i] - 'a']++;
            sh[s[i] - 'a']++;
        }
        for (int i = ps; i < ss; i++)
        {
            if (sh == ph) ans.push_back(i - ps);
            sh[s[i] - 'a']++;
            sh[s[i - ps] - 'a']--;
        }
        if (sh == ph) ans.push_back(ss - ps);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}