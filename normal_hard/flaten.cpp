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
    void flatten(TreeNode *root)
    {
        this->tmp = nullptr;
        postorder(root);
    }

private:
    TreeNode *tmp;
    void postorder(TreeNode *&root)
    {
        if (!root)
            return;
        postorder(root->right);
        postorder(root->left);
        root->right = tmp;
        root->left = nullptr;
        tmp = root;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}