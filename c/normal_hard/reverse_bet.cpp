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

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head)
            return head;
        ListNode *dummy = new ListNode(1), *pre, *endnext, *walk, *tmp;
        dummy->next = head;
        walk = dummy;
        for (int i = 0; i <= n; i++, walk = walk->next)
        {
            if (i == m - 1)
                pre = walk;
            if (i == n)
                endnext = walk->next;
        }
        walk = pre->next;
        pre->next = endnext;
        for (int i = m; i <= n; i++)
        {
            tmp = walk->next;
            walk->next = pre->next;
            pre->next = walk;
            walk = tmp;
        }
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}