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
    // vector<vector<int>> levelOrderBottom(TreeNode *root)
    // {
    //     vector<vector<int>> res;
    //     Traverse(root, 1, res);
    //     return res;
    // }
    // void Traverse(TreeNode* root, int level, vector<vector<int>> & v){
    //     if(!root) return;
    //     if(level > v.size())
    //         v.push_back(vector<int>(0));
    //     v[level-1].push_back(root->val);
    //     Traverse(root->left, level+1, v);
    //     Traverse(root->right,level+1, v);
    // }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> Q, nextLevel_Q;
        vector<int> nowLevel;
        Q.push(root);
        while (Q.size())
        {
            while (Q.size())
            {
                TreeNode *node = Q.front();
                Q.pop();
                nowLevel.push_back(node->val);
                if (node->left)
                    nextLevel_Q.push(node->left);
                if (node->right)
                    nextLevel_Q.push(node->right);
            }
            res.push_back(nowLevel);
            nowLevel.clear();
            swap(Q, nextLevel_Q); // now Q is empty, let Q be the next level Q.
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}