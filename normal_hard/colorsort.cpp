// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count[3] = {0}, c = 0;
        for(auto i : nums)
            count[i]++;
        for(int i = 0 ; i < 3; i++)
            while(count[i]--)
                nums[c++] = i;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}