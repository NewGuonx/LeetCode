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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow, *fast, *b;
        b = slow = fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                while (b != slow)
                {
                    b = b->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}