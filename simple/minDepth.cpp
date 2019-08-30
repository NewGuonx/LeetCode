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
    int minDepth(const TreeNode *root)
    {
        return minDepth(root, false);
    }

  private:
    int minDepth(const TreeNode *root, bool sibling)
    {
        if (!root) return sibling ? 1<<30 : 0;
        return 1 + min(minDepth(root->left, root->right != NULL),
                       minDepth(root->right, root->left != NULL));
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    
    return 0;
}