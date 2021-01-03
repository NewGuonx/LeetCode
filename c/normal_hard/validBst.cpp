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
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        TreeNode *p = nullptr;
        return inorder(root, p);
    }

private:
    bool inorder(TreeNode *root, TreeNode *&p)
    {
        if (!root)
            return true;
        bool f = inorder(root->left, p) && (!p || p->val < root->val);
        p = root;
        return f && inorder(root->right, p);
    }
};