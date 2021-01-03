// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int ans = 0;
        for (auto i : nums)
            st.insert(i);
        for (auto i : st)
        {
            if (!st.count(i - 1))
            {
                int tmp = 1;
                while (st.count(i + 1))
                    i++, tmp++;
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}