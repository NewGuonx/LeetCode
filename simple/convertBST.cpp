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
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        Inorder(root, sum);
        return root;
    }

    void Inorder(TreeNode *root, int &sum)
    {
        if (!root)
            return;
        if (root->right)
            Inorder(root->right, sum);
        int temp = sum;
        sum += root->val;
        root->val += temp;
        if (root->left)
            Inorder(root->left, sum);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    Solution s;
    root = s.convertBST(root);
    cout << root->left->val;
    return 0;
}