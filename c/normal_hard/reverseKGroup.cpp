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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next || k < 2)
            return head;
        ListNode *dummy = new ListNode(1), *b, *walk, *prev = dummy, *tmp;
        walk = b = dummy->next = head;
        for (int i = 1; walk; i++, walk = tmp)
        {
            tmp = walk->next;
            if (i % k == 0)
            {
                prev = __reverse(prev, b, walk);
                b = tmp;
            }
        }
        return dummy->next;
    }
    ListNode *__reverse(ListNode *pre, ListNode *_first, ListNode *_last)
    {
        ListNode *tmp, *walk = _first, *_end = _last->next;
        pre->next = _end;
        while (walk != _end)
        {
            tmp = walk->next;
            walk->next = pre->next;
            pre->next = walk;
            walk = tmp;
        }
        return _first;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}