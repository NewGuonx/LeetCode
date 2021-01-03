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
    int __trav(TreeNode *root, int _sum)
    {
        if (!root)
            return 0;
        _sum = 10 * _sum + root->val;
        if (!root->left && !root->right)
            return _sum;
        return __trav(root->left, _sum) +
               __trav(root->right, _sum);
    }
    int sumNumbers(TreeNode *root)
    {
        return __trav(root, 0);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}