// author - newguo@sonaspy.cn
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next || k < 2)
            return head;
        ListNode *next, *pre, *walk, *dummy = new ListNode(1), *last, *post;
        dummy->next = head;
        for (pre = dummy, last = head; last != nullptr; last = pre->next)
        {
            for (int i = 1; i < k && last != nullptr; i++)
                last = last->next;
            if (!last)
                break;
            pre = func(pre, pre->next, last);
        }
        return dummy->next;
    }
    ListNode *func(ListNode *pre, ListNode *begin, ListNode *end)
    {
        ListNode *end_next = end->next;
        for (ListNode *p = begin, *cur = p->next, *next = cur->next; cur != end_next; p = cur, cur = next, next = next ? next->next : nullptr)
            cur->next = p;
        begin->next = end_next;
        pre->next = end;
        return begin;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}