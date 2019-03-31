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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        maxDepth(root);
        for (auto i : mp)
            if (i.second > res)
                res = i.second;
        return res;
    }
    int maxDepth(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = maxDepth(node->left),
            right = maxDepth(node->right);
        mp[node] = left + right;
        return (left > right ? left : right) + 1;
    }
    unordered_map<TreeNode *, int> mp;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}