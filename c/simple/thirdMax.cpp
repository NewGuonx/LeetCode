// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int thirdMax(vector<int> &nums)
    {
        unordered_set<int> st;
        vector<int> tmp;
        for (auto i : nums)
        {
            if (!st.count(i))
            {
                st.insert(i);
                tmp.push_back(i);
            }
        }
        int n = tmp.size() - 1;
        if (n == 1)
            return max(tmp[0], tmp[1]);
        if (n == 0)
            return tmp[0];
        for (int j = 0; j < 3; j++, n--)
        {
            int max = -2147483648, c = 0;
            for (int i = 0; i <= n; i++)
            {
                if (tmp[i] > max)
                {
                    max = tmp[i];
                    c = i;
                }
            }
            swap(tmp[c], tmp[n]);
        }
        return tmp[n + 1];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}