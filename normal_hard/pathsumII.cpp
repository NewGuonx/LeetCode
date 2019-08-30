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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return res;
        this->sum = sum;
        this->tmpsum = 0;
        dfs(root);
        return res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    int sum, tmpsum;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        path.push_back(root->val);
        tmpsum += root->val;
        if (!root->left && !root->right && tmpsum == sum)
            res.push_back(path);
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
        tmpsum -= root->val;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}