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
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        this->res = INT_MIN;
        postOrder(root);
        return res;
    }

private:
    int res;
    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int l, r, tmp;
        l = postOrder(root->left);
        r = postOrder(root->right);
        l = l > 0 ? l : 0;
        r = r > 0 ? r : 0;
        tmp = root->val + l + r;
        res = max(res, tmp); // comparison
        tmp = max(l, r);
        tmp = tmp > 0 ? tmp + root->val : root->val;
        return tmp;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}