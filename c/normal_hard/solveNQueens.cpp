// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->columns = vector<bool>(n, false);           // if there is a queen in this column.
        this->main_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->vice_diag = vector<bool>(2 * n - 1, false); // if there is a queen in this diag
        this->C = vector<int>(n, -1);                     // each row's queen put in which column
        vector<vector<string>> res;
        this->N = n;
        dfs(res, 0);
        return res;
    }

private:
    vector<bool> columns, main_diag, vice_diag;
    vector<int> C;
    int N;
    void dfs(vector<vector<string>> &res, int row)
    {
        if (row == N)
        {
            res.push_back(vector<string>());
            for (int i = 0; i < N; i++)
            {
                string s(N, '.');
                for (int j = 0; j < N; j++)
                    if (j == C[i])
                        s[j] = 'Q';
                res.back().push_back(s);
            }
            return;
        }
        for (int j = 0; j < N; j++)
        {
            const bool ok = !columns[j] && !main_diag[row - j + N - 1] && !vice_diag[row + j];
            if (ok)
            {
                C[row] = j;
                columns[j] = main_diag[row - j + N - 1] = vice_diag[row + j] = true;
                dfs(res, row + 1);
                C[row] = -1;
                columns[j] = main_diag[row - j + N - 1] = vice_diag[row + j] = false;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}