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
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root) return nullptr;
        TreeNode *tmp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = tmp;
        return root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}