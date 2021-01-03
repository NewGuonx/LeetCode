// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> v1, v2;
        for (auto i : nums1)
            v1[i]++;
        sort(nums2.begin(), nums2.end());
        for (auto i : nums2)
        {
            if (v1.count(i) && v2[i] < v1[i])
            {
                res.push_back(i);
                v2[i]++;
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