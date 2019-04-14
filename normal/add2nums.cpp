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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        int carry = 0, num, a, b;
        ListNode *walk = &dummy, *pa = l1, *pb = l2;
        while (pa || pb)
        {
            a = !pa ? 0 : pa->val;
            b = !pb ? 0 : pb->val;
            num = (a + b + carry) % 10;
            carry = (a + b + carry) / 10;
            walk->next = new ListNode(num);
            walk = walk->next;
            pa = !pa ? nullptr : pa->next;
            pb = !pb ? nullptr : pb->next;
        }
        if(carry)walk->next = new ListNode(1);
        return dummy.next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}