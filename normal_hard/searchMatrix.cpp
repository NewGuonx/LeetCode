// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        const int m = matrix.size(), n = matrix.front().size();
        int lo = 0, hi = n * m, mid, v;
        while (lo < hi)
        {
            mid = lo + (hi - lo) / 2;
            v = matrix[mid / n][mid % n];
            if (v == target)
                return true;
            else if (v < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}