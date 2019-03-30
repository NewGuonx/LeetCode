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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums.begin(), nums.end());
    }
    TreeNode *sortedArrayToBST(vector<int>::iterator first, vector<int>::iterator last)
    {
        const auto len = distance(first, last);
        if (len <= 0)
            return nullptr;
        auto mid = first + len / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);
        return root;
    }
};

TreeNode *ArrayToBST(int *first, int *last)
{
    auto len = distance(first, last);
    if (len <= 0) return nullptr;
    auto mid = first + len / 2;
    TreeNode *root = new TreeNode(*mid);
    root->left = ArrayToBST(first, mid);
    root->right = ArrayToBST(mid + 1, last);
    return root;
}

TreeNode *sortedArrayToBST(int *&nums, int n)
{
    return ArrayToBST(nums, nums + n);
}

void order(TreeNode *&root)
{
    if (!root) return;
    if (root->left) order(root->left);
    cout << root->val << " ";
    if (root->right) order(root->right);
}

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int *nums = new int[10];
    for (int i = 0; i < 10; i++)
        nums[i] = i;
    TreeNode *root = sortedArrayToBST(nums, 10);
    order(root);
    return 0;
}