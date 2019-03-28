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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode *p = root;
        while(s.size() || p){
            if(p){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}