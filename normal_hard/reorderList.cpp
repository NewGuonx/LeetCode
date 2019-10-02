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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        ListNode *posthalf = head, *tail = head, *last = nullptr, *walk, *tmp;
        for (; tail && tail->next; last = posthalf, posthalf = posthalf->next, tail = tail->next->next)
            ;
        last->next = nullptr; // cut middle;

        posthalf = reverse(posthalf); // reverse post half part

        walk = head;
        while (walk->next)
        {
            tmp = walk->next;
            walk->next = posthalf;
            posthalf = posthalf->next;
            walk->next->next = tmp;
            walk = tmp;
        }
        walk->next = posthalf;
    }
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *walk = head, *dummy = new ListNode(0), *tmp;
        while (walk)
        {
            tmp = walk->next;
            walk->next = dummy->next;
            dummy->next = walk;
            walk = tmp;
        }
        return dummy->next;
    }
};

int main(int argc, char const **argv)
{
    /* code */
    //test();

    return 0;
}