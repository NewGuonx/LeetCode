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
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p)
        {
            ++length;
            p = p->next;
        }
        for (int len = 1; len < length; len *= 2)
        {
            auto cur = dummyHead.next;
            auto p = &dummyHead;
            while (cur)
            {
                auto left = cur;
                auto right = truncate(left, len); // left->@->@ right->@->@->@...
                cur = truncate(right, len);       // left->@->@ right->@->@  cur->@->...
                p->next = merge(left, right);
                while (p->next)
                    p = p->next;
            }
        }
        return dummyHead.next;
    }
    ListNode *truncate(ListNode *head, int n)
    {
        while (--n && head)
            head = head->next;
        if (!head)
            return nullptr;
        auto next = head->next;
        head->next = nullptr;
        return next;
    }
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        for (; l1 && l2; p = p->next)
        {
            if (l1->val < l2->val)
                p->next = l1, l1 = l1->next;
            else
                p->next = l2, l2 = l2->next;
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}