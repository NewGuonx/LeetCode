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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root) return 0;
        return calcu(root->left, true)+calcu(root->right, false);
    }
    int calcu(TreeNode *root, bool isleft)
    {
        if (!root) return 0;
        if (isleft && !root->left && !root->right) return root->val;
        return calcu(root->left, true) + calcu(root->right, false);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}