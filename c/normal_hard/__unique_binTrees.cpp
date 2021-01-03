// author -sonaspy@outlook.com
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
    int numTrees(int n)
    {
        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int k = 1; k <= i; k++)
                f[i] += f[k - 1] * f[i - k];
        return f[n];
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>();
        return __generate_trees(1, n);
    }
    vector<TreeNode *> __generate_trees(int begin, int end)
    {
        vector<TreeNode *> res;
        if (end < begin)
        {
            res.push_back(nullptr);
            return res;
        }
        for (int i = begin; i <= end; ++i)
        {
            vector<TreeNode *> left_trees = __generate_trees(begin, i - 1);
            vector<TreeNode *> right_trees = __generate_trees(i + 1, end);
            for (auto l : left_trees)
            {
                for (auto r : right_trees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
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