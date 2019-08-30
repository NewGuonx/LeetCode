// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        int n = 0;
        h = head;
        while (head)
        {
            head = head->next;
            n++;
        }
        return sortedListToBST(0, n - 1);
    }

private:
    ListNode *h;
    TreeNode *sortedListToBST(int lo, int hi)
    {
        if (hi < lo)
            return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode *left = sortedListToBST(lo, mid - 1);
        TreeNode *p = new TreeNode(h->val);
        p->left = left;
        h = h->next;
        TreeNode *right = sortedListToBST(mid + 1, hi);
        p->right = right;
        return p;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}