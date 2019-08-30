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
        inorder(root);
        return f;
    }

private:
    bool f = true;
    int64_t v = -(INT64_MAX);
    void inorder(TreeNode *root)
    {
        if (!f)
            return;
        if (root->left)
            inorder(root->left);
        if (f)
        {
            f = (root->val > v) ? true : false;
            v = root->val;
        }
        if (root->right)
            inorder(root->right);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}