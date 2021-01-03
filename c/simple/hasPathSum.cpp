// author -sonaspy@outlook.com
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

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
    bool hasPathSum(TreeNode *root, int sum)
    {
        if(!root) return false;
        if(!root->left && !root->right)
            return root->val == sum;
        return hasPathSum(root->left, sum -root->val) || hasPathSum(root->right, sum - root->val);

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}