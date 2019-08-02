// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode * dummy = new ListNode(0), *p = dummy;
        for(; l1 && l2; p = p->next){
            if(l1->val > l2->val)
                p->next = l2, l2 = l2->next;
            else p->next = l1, l1 = l1->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}