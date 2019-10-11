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
        TreeNode *p = nullptr;
        f = 0;
        inorder(root, p);
        f = 0, p = nullptr;
        inorder_(root, p);
        swap(v1->val, v2->val);
    }

private:
    TreeNode *v1, *v2;
    int f;
    void inorder(TreeNode *root, TreeNode *&p)
    {
        if (!root || f)
            return;
        inorder(root->left, p);
        if (!(!p || root->val > p->val))
        {
            v1 = p;
            f = 1;
            return;
        }
        p = root;
        inorder(root->right, p);
    }
    void inorder_(TreeNode *root, TreeNode *&p)
    {
        if (!root || f)
            return;
        inorder_(root->right, p);
        if (!(!p || root->val < p->val))
        {
            v2 = p;
            f = 1;
            return;
        }
        p = root;
        inorder_(root->left, p);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}