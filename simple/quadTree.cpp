// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Node
{
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution
{
  public:
    Node *quadTree(vector<vector<int>> &grid, int x, int y, int offset)
    {
        if (offset <= 0)
            return nullptr;
        //Check if the content of the area is consistent
        for (int i = x; i < x + offset; ++i)
        {
            for (int j = y; j < y + offset; ++j)
            {
                if (grid[i][j] != grid[x][y])
                {
                    return new Node(false, false, //!isLeaf
                                    quadTree(grid, x, y, offset / 2),
                                    quadTree(grid, x, y + offset / 2, offset / 2),
                                    quadTree(grid, x + offset / 2, y, offset / 2),
                                    quadTree(grid, x + offset / 2, y + offset / 2, offset / 2));
                }
            }
        } //isLeaf
        return new Node(grid[x][y], true, nullptr, nullptr, nullptr, nullptr);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        return quadTree(grid, 0, 0, grid.size());
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}