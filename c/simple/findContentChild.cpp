// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int sum = 0;
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end());
        for (auto i : g)
        {
            if (s.empty())
                break;
            while (s.size() && s.back() < i)
                s.pop_back();
            if (s.empty())
                break;
            sum++;
            s.pop_back();
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}