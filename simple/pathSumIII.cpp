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
    int pathSum(TreeNode *root, int sum)
    {
        int cnt = 0, thissum = 0;
        preorder(root, cnt, sum, thissum);
        return cnt;
    }
    void preorder(TreeNode *root, int &cnt, int &sum, int &thissum)
    {
        if (!root)
            return;
        function(root, cnt, sum, thissum);
        if (root->left)
            preorder(root->left, cnt, sum, thissum);
        if (root->right)
            preorder(root->right, cnt, sum, thissum);
    }
    void function(TreeNode *root, int &cnt, int &sum, int &thisum)
    {
        if (!root)
            return;
        thisum += root->val;
        if (thisum == sum)
            cnt++;
        if (root->left)
            function(root->left, cnt, sum, thisum);
        if (root->right)
            function(root->right, cnt, sum, thisum);
        thisum -= root->val;
        return;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}