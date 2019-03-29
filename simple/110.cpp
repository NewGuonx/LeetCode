// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

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
    bool isBalanced(TreeNode *root)
    {
        return getFactor(root) >= 0;
    }
    int getFactor(TreeNode* root){
        if(!root) return 0;
        int left = getFactor(root->left);
        int right = getFactor(root->right);
        if( left == -1|| right == -1 || abs(left - right) > 1 ) return -1;
        return max(left,right)+1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}