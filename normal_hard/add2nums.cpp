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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        int carry = 0, num, a, b;
        ListNode *walk = &dummy, *pa = l1, *pb = l2;
        while (pa || pb)
        {
            a = pa ? pa->val : 0;
            b = pb ? pb->val : 0;
            num = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            walk->next = new ListNode(num);
            walk = walk->next;
            pa = pa ? pa->next : nullptr;
            pb = pb ? pb->next : nullptr;
        }
        if (carry)
            walk->next = new ListNode(carry);
        return dummy.next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}