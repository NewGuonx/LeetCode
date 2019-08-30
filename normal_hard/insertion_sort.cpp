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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(INT_MIN);
        for (ListNode *cur = head; cur;)
        {
            ListNode *pos = findPos(&dummy, cur->val), *tmp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = tmp;
        }
        return dummy.next;
    }
    ListNode *findPos(ListNode *head, int x)
    {
        ListNode *pre = head;
        for (ListNode *cur = head; cur && cur->val <= x; pre = cur, cur = cur->next)
            ;
        return pre;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}