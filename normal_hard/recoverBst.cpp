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
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root);
        int i, j;
        for (i = 1; i < v.size() && v[i]->val > v[i - 1]->val; i++)
            ;
        for (j = v.size() - 2; j > -1 && v[j]->val < v[j + 1]->val; j--)
            ;
        swap(v[i - 1]->val, v[j + 1]->val);
    }

private:
    vector<TreeNode *> v;
    void inorder(TreeNode *root)
    {
        if (root->left)
            inorder(root->left);
        v.push_back(root);
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