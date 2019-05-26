// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0, tmp;
        heights.push_back(0);
        stack<int> s;
        for (int i = 0; i < heights.size();)
        {
            if (s.empty() || heights[i] > heights[s.top()])
                s.push(i++);
            else
            {
                tmp = s.top(), s.pop();
                res = max(res, heights[tmp] * s.empty() ? i : i - s.top() - 1);
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