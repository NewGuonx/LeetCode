// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_set<int> v1, v2;
        for (auto i : nums1)
            v1.insert(i);
        for (auto i : nums2)
        {
            if (v1.count(i) && !v2.count(i))
            {
                res.push_back(i);
                v2.insert(i);
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}