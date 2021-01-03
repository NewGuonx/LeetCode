// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size(), m = board[0].size();
        this->board = board;
        this->vis = vector<vector<bool>>(n, vector<bool>(m, false));
        this->word = word;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (dfs(0, i, j))
                    return true;
        return false;
    }

private:
    vector<vector<bool>> vis;
    vector<vector<char>> board;
    string word;
    int n, m;
    bool dfs(int c, int i, int j)
    {
        if (c == word.size())
            return true;
        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;
        if (vis[i][j] || board[i][j] != word[c])
            return false;
        vis[i][j] = true;
        bool ret = dfs(c + 1, i - 1, j) || dfs(c + 1, i, j - 1) || dfs(c + 1, i + 1, j) || dfs(c + 1, i, j + 1);
        vis[i][j] = false;
        return ret;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}