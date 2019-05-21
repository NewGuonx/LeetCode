// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double ans, a1, a2;
        int midpos = (nums1.size() + nums2.size()) / 2, m = -1, pb = 0, pa = 0, last;
        bool f = ((nums1.size() + nums2.size()) % 2 == 0);
        if (nums2.empty())
            return nums1.size() % 2 == 0 ? (nums1[midpos] + nums1[midpos - 1]) * 1.0 / 2 : nums1[midpos] * 1.0;
        if (nums1.empty())
            return nums2.size() % 2 == 0 ? (nums2[midpos] + nums2[midpos - 1]) * 1.0 / 2 : nums2[midpos] * 1.0;
        for (; pa < nums1.size(); pa++)
        {
            for (; pb < nums2.size() && nums2[pb] < nums1[pa]; pb++)
            {
                m++;
                if (m == midpos)
                    return f ? (last + nums2[pb]) * 1.0 / 2 : nums2[pb] * 1.0;
                last = nums2[pb];
            }
            m++;
            if (m == midpos)
                return f ? (last + nums1[pa]) * 1.0 / 2 : nums1[pa] * 1.0;
            last = nums1[pa];
        }
        for (; pb < nums2.size(); pb++)
        {
            m++;
            if (m == midpos)
                return f ? (last + nums2[pb]) * 1.0 / 2 : nums2[pb] * 1.0;
            last = nums2[pb];
        }
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> a, b;
    a.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    Solution s;
    cout << s.findMedianSortedArrays(a, b);
    return 0;
}