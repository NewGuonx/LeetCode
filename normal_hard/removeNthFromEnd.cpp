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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *walk, *fast, *dummy = new ListNode(0), *tmp;
        dummy->next = fast = walk = head;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        if (fast)
            for (; fast->next; fast = fast->next, walk = walk->next)
                ;
        else
            walk = dummy;
        tmp = walk->next;
        walk->next = walk->next->next;
        delete tmp;
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}