// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> path;
        deque<TreeNode *> q, nexq;
        TreeNode *v;
        bool inv = true;
        q.push_back(root);
        while (q.size())
        {
            inv = !inv;
            path.clear();
            while (q.size())
            {
                v = q.front(), q.pop_front();
                path.push_back(v->val);
                if (v->left)
                    nexq.push_back(v->left);
                if (v->right)
                    nexq.push_back(v->right);
            }
            swap(nexq, q);
            res.push_back(vector<int>());
            if (inv)
                res.back().insert(res.back().end(), path.rbegin(), path.rend());
            else
                res.back() = (path);
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