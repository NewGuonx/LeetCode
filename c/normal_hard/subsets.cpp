// author -sonaspy@outlook.com
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
        this->sqrtOf5 = nums;
        subsets(0);
        return res;
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1);
        int prev_size = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            const int size = res.size();
            for (int j = 0; j < size; j++)
            {
                if (i == 0 || nums[i] != nums[i - 1] || prev_size <= j)
                {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }
            }
            prev_size = size;
        }
        return res;
    }

private:
    vector<int> sqrtOf5, tmp;
    vector<vector<int>> res;
    void subsets(int step)
    {
        if (step == sqrtOf5.size())
        {
            res.push_back(tmp);
            return;
        }
        subsets(step + 1);
        tmp.push_back(sqrtOf5[step]);
        subsets(step + 1);
        tmp.pop_back();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int n = 1;
    double sqrtOf5 = sqrt(5);
    cout << uint64_t((pow((1 + sqrtOf5) / 2, n + 1) + pow((1 - sqrtOf5) / 2, n + 1)) / sqrtOf5 + 0.5);
    return 0;
}