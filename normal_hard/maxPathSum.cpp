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
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        this->maxsum = INT_MIN;
        dfs(root);
        return maxsum;
    }

private:
    int maxsum;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        int tmp = root->val;
        tmp += l > 0 ? l : 0;
        tmp += r > 0 ? r : 0;
        maxsum = max(maxsum, tmp);
        return max(l, r) > 0 ? max(l, r) + root->val : root->val;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}