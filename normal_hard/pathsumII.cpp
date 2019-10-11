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
    vector<vector<int>> pathSum(TreeNode *__root, int sum)
    {
        if (!__root)
            return res;
        this->sum = sum;
        this->__tpsum = 0;
        __trav(__root);
        return res;
    }

private:
    vector<int> __path;
    vector<vector<int>> res;
    int sum, __tpsum;
    void __trav(TreeNode *__root)
    {
        if (!__root)
            return;
        __path.push_back(__root->val);
        __tpsum += __root->val;
        if (!__root->left && !__root->right && __tpsum == sum)
            res.push_back(__path);
        __trav(__root->left);
        __trav(__root->right);
        __path.pop_back();
        __tpsum -= __root->val;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}