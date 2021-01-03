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
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *slow, *fast;
        for (slow = fast = head; fast->next && fast->next->next; fast = fast->next->next, slow = slow->next)
            ;
        fast = slow, slow = slow->next;
        fast->next = nullptr;
        return __merge(sortList(head), sortList(slow));
    }
    ListNode *__merge(ListNode *l1, ListNode *l2)
    {
        ListNode *_dummy = new ListNode(0), *walk = _dummy;
        for (; l1 && l2; walk = walk->next)
        {
            if (l1->val < l2->val)
                walk->next = l1, l1 = l1->next;
            else
                walk->next = l2, l2 = l2->next;
        }
        walk->next = l1 ? l1 : l2;
        return _dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}