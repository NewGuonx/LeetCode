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
    vector<int> preOrderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (s.size() || p)
        {
            while (p)
            {
                result.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p = root;
        while (s.size() || p)
        {
            while (p)
            {
                s.push(p);
                p = p->left;
            }
            if (s.size())
            {
                p = s.top();
                s.pop();
                result.push_back(p->val);
                p = p->right;
            }
        }
        return result;
    }
    vector<int> preorder(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> s;
        s.push(root);
        while (s.size())
        {
            root = s.top();
            s.pop();
            result.push_back(root->val);
            if (root->right)
                s.push(root->right);
            if (root->left)
                s.push(root->left);
        }
        return result;
    }
    vector<int> postorder(TreeNode *root)
    {
        vector<int> result;
        if(!root) return result;
        stack<pair<TreeNode *, bool>> s;
        s.push(make_pair(root, false));
        bool isMyTurn;
        while (s.size())
        {
            root = s.top().first;
            isMyTurn = s.top().second;
            s.pop();
            if (isMyTurn)
                result.push_back(root->val);
            else
            {
                s.push(make_pair(root, true));
                if(root->right)
                s.push(make_pair(root->right, false));
                if(root->left)
                s.push(make_pair(root->left, false));
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
    order(root);
    cout << endl;
    vector<int> v = s.postorder(root);
    for (auto i : v)
        cout << i << " ";
    return 0;
}