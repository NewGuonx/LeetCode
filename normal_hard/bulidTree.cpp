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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->inorder = inorder;
        this->preorder = preorder;
        return __build1(0, 0, inorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        this->inorder = inorder;
        this->postorder = postorder;
        return __build2(inorder.size() - 1, 0, inorder.size() - 1);
    }

private:
    vector<int> preorder, inorder, postorder;
    TreeNode *__build1(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode *node = new TreeNode(preorder[root]);
        while (i < hi && inorder[i] != preorder[root])
            i++;
        node->left = __build1(root + 1, lo, i - 1);
        node->right = __build1(root + 1 + i - lo, i + 1, hi);
        return node;
    }
    TreeNode *__build2(int root, int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int i = lo;
        TreeNode *node = new TreeNode(postorder[root]);
        while (i < hi && inorder[i] != postorder[root])
            i++;
        node->left = __build2(root - 1 + i - hi, lo, i - 1);
        node->right = __build2(root - 1, i + 1, hi);
        return node;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}