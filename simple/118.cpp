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
#include <deque>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        if (!numRows)
            return res;
        res.push_back(vector<int>(1, 1));
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> current(i, 1), &prev = res[i - 2];
            for (int j = 1; j <= i - 2; j++)
                current[j] = prev[j - 1] + prev[j];
            res.push_back(current);
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    int n;
    cin >> n;
    vector<vector<int>> res = s.generate(n);
    deque<string> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
        {
            cout << " ";
        }
        for (auto j : res[i])
        {
            printf("%d ", j);
        }
        cout << endl;
    }
    return 0;
}