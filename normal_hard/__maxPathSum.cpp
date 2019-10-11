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
        this->max_sum = INT_MIN;
        postOrder(root);
        return max_sum;
    }

private:
    int max_sum;
    int postOrder(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = postOrder(root->left);
        int r = postOrder(root->right);
        int tmp = root->val;
        tmp += l > 0 ? l : 0;
        tmp += r > 0 ? r : 0;
        max_sum = max(max_sum, tmp); // comparison
        tmp = max(l, r);
        return tmp > 0 ? tmp + root->val : root->val;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}