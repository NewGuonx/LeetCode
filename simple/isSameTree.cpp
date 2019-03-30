// author - newguo@sonaspy.cn
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q )
            return false;
        if (p->val == q->val)
        {
            bool f1 = isSameTree(p->left, q->left);
            bool f2 = isSameTree(p->right, q->right);
            return f1 && f2;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}