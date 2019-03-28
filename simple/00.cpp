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
void Insert(TreeNode *&root, int data)
{
    if (!root)
    {
        root = new TreeNode(data);
        return;
    }
    if (data < root->val)
        Insert(root->left, data);
    else
        Insert(root->right, data);
}
class Solution
{
  public:
    vector<int> preOrder(TreeNode *root)
    {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode *p = root;
        while (s.size() || p)
        {
            if (p)
            {
                result.push_back(p->val);
                if (p->right)
                    s.push(p->right);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                if (p->right)
                    s.push(p->right);
                p = p->left;
            }
        }
        return result;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<const TreeNode *> s;
        const TreeNode *p = root;
        while (s.size() || p)
        {
            if (p)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
};

void order(TreeNode *root)
{
    if (!root)
        return;
    order(root->left);
    order(root->right);
    cout << root->val << " ";
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    TreeNode *root = nullptr;
    int a[] = {10, 8, 11, 6, 15, 2, 5, 9, 7, 3, 1, 13, 14, 4, 12};
    for (int i = 0; i < 14; i++)
        Insert(root, a[i]);
    Solution s;
    cout << "Pre\n";
    // order(root);
    vector<int> v = s.inorderTraversal(root);
    for (auto i : v)
        cout << i << " ";
    return 0;
}