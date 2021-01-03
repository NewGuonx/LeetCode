// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - 1 - i][j]);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}