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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root) getPath(root, "", res);
        return res;
    }
    void getPath(TreeNode *root, string single_path, vector<string> &res)
    {
        if (!root->left && !root->right)
            res.push_back(single_path + to_string(root->val));
        if (root->left)
            getPath(root->left, single_path + to_string(root->val) + "->", res);
        if (root->right)
            getPath(root->right, single_path + to_string(root->val) + "->", res);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}