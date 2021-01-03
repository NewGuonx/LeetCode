// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Node
{
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
  public:
    // vector<vector<int>> levelOrder(Node *root)
    // {
    //     vector<vector<int>> res;
    //     if (!root) return res;
    //     res.push_back(vector<int>(1, root->val));
    //     Level(root, 1, res);
    //     return res;
    // }
    // void Level(Node *root, int level, vector<vector<int>> &res)
    // {
    //     if(!root)return;
    //     if (level > res.size()-1)
    //         res.push_back(vector<int>());
    //     for (auto &i : root->children)
    //     {
    //         res[level].push_back(i->val);
    //         Level(i, level + 1, res);
    //     }
    // }

    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<Node *> Q, Next_Q;
        vector<int> curL;
        Q.push(root);
        while (Q.size())
        {
            while (Q.size())
            {
                Node *tmp = Q.front();
                Q.pop();
                curL.push_back(tmp->val);
                for (auto &i : tmp->children)
                    Next_Q.push(i);
            }
            res.push_back(curL);
            curL.clear();
            swap(Q, Next_Q);
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