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
    int sumNumbers(TreeNode *root)
    {
        if (!root)
            return 0;
        anssum = 0;
        dfs(root);
        return anssum;
    }
    string path;
    int anssum;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        string s = to_string(root->val);
        path += s;
        if (!root->left && !root->right)
            anssum += stoi(path);
        dfs(root->left);
        dfs(root->right);
        for (int i = 0; i < s.size(); i++)
            path.pop_back();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}