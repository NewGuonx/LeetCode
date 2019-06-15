// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;
        n = board.size(), m = board[0].size();
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; j++)
        {
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                board[i][j] = board[i][j] == '1' ? 'O' : 'X';
    }

private:
    int n, m;
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i > -1 && i < n && j > -1 && j < m && board[i][j] == 'O')
        {
            board[i][j] = '1';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}