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
        ListNode *slow = head, *fast = head, *walk, *tmp;
        for (; fast->next && fast->next->next; slow = slow->next, fast = fast->next->next)
            ;
        fast = slow, slow = slow->next;
        fast->next = nullptr;

        slow = __reverse(slow); // __reverse post half part

        walk = head;
        while (walk->next)
        {
            tmp = walk->next;
            walk->next = slow;
            slow = slow->next;
            walk->next->next = tmp;
            walk = tmp;
        }
        walk->next = slow;
    }
    ListNode *__reverse(ListNode *head)
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