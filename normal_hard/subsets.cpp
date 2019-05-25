// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        this->s = nums;
        subsets(0);
        return res;
    }

private:
    vector<int> s, path;
    vector<vector<int>> res;
    void subsets(int step)
    {
        if (step == s.size())
        {
            res.push_back(path);
            return;
        }
        subsets(step + 1);
        path.push_back(s[step]);
        subsets(step + 1);
        path.pop_back();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}