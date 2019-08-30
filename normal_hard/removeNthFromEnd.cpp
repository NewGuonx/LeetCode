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
        ListNode *walk, *pre, *dummy = new ListNode(0);
        dummy->next = head;
        pre = dummy;
        walk = head;
        while (walk)
        {
            walk = walk->next;
            count++;
        }
        if (!n || n > count)
            return head;
        n = count - n;
        count = 0;
        walk = head;
        while (walk && count < n)
        {
            pre = walk;
            walk = walk->next;
            count++;
        }
        pre->next = walk->next;
        return dummy->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}