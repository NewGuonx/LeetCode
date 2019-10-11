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
    void flatten(TreeNode *root)
    {
        this->p = nullptr;
        postorder(root);
    }
private:
    TreeNode *p;
    void postorder(TreeNode *&root)
    {
        if (!root)
            return;
        postorder(root->right), postorder(root->left);
        root->right = p, root->left = nullptr;
        p = root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}