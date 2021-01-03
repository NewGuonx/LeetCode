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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ans = nullptr;
        unordered_set<ListNode *> st;
        while (headA)
        {
            st.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (st.count(headB))
            {
                ans = headB;
                break;
            }
            headB = headB->next;
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}