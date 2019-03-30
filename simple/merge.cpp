// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> v;
        nums1.erase(nums1.begin()+m, nums1.end());
        v.resize(m+n);
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
        nums1 = v;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n1[] = {1, 3, 5, 0, 0, 0}, n2[] = {2, 6, 8};
    vector<int> v1(n1, n1 + 6), v2(n2, n2 + 3);
    Solution s;
    s.merge(v1,3 ,v2, 3);
    for(auto i : v1) cout << i << " ";
    return 0;
}