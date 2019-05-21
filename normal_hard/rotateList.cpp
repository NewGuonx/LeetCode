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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || (!k))
            return head;
        ListNode *walk, *pre, *post, *mid;
        int step = 0, n = 0;

        for (walk = head; walk; walk = walk->next, n++)
            ;
        k %= n;
        if (!k)
            return head;
        for (walk = head; walk; walk = walk->next, step++)
        {
            if (step == n - k - 1)
            {
                pre = walk;
                mid = walk->next;
            }
            if (!walk->next)
                post = walk;
        }
        post->next = head;
        pre->next = nullptr;
        return mid;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}