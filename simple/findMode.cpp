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
    vector<int> findMode(TreeNode *root)
    {
        unordered_map<int, int> mp;
        int max_t = -1;
        inorder(root, mp, max_t);
        vector<int> res;
        for(auto i : mp)
            if(i.second == max_t)
                res.push_back(i.first);
        return res;
    }
    void inorder(TreeNode *root, unordered_map<int, int> &mp, int &max_t)
    {
        if (!root) return;
        inorder(root->left, mp, max_t);
        mp[root->val]++;
        if (mp[root->val] >= max_t)
            max_t = mp[root->val];
        inorder(root->right, mp, max_t);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}