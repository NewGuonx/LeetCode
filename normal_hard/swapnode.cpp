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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *next, *pre, *walk, *dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy, walk = pre->next, next = walk->next;
        for (; next; pre = walk, walk = walk->next, next = walk ? walk->next : nullptr)
        {
            pre->next = next;
            walk->next = next->next;
            next->next = walk;
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