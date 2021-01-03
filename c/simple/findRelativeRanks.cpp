// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
#define NO_1 ("Gold Medal")
#define NO_2 ("Silver Medal")
#define NO_3 ("Bronze Medal")

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<int> idx(nums.size());
        vector<string> ret(nums.size());
        int i = 0;
        generate(idx.begin(), idx.end(), [&]() { return i++; });

        sort(idx.begin(), idx.end(), [&nums](int a, int b) {
            return nums[a] > nums[b];
        });
        for (i = 0; i < idx.size(); i++)
        {
            if (i == 0)
                ret[idx[i]] = "Gold Medal";
            else if (i == 1)
                ret[idx[i]] = "Silver Medal";
            else if (i == 2)
                ret[idx[i]] = "Bronze Medal";
            else
                ret[idx[i]].assign(to_string(i + 1));
        }
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}