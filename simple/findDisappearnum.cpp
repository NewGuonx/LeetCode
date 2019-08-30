// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n[nums.size() + 1] = {0};
        vector<int> res;
        for (auto i : nums)
            n[i] = 1;
        for (int i = 1; i <= nums.size(); i++)
            if (n[i] == 0)
                res.push_back(i);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}