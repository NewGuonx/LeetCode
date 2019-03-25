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
        
        ListNode* head = new ListNode(0),
                        * walk1 = l1, *walk2 = l2,
                        *newcur = head;
        while(walk1 && walk2){
            if(walk1->val == walk2->val){
                newcur->next = walk1;
                walk1 = walk1->next;
                newcur = newcur->next;
                newcur->next = walk2;
                walk2 = walk2->next;
                newcur = newcur->next;
            }
            else if(walk1->val < walk2->val){
                newcur->next = walk1;
                newcur = newcur->next;
                walk1 = walk1->next;
            }
            else if (walk2->val < walk1->val)
            {
                newcur->next = walk2;
                newcur = newcur->next;
                walk2 = walk2->next;
            }
        }
        if(walk2 == nullptr){
            while(walk1){
                newcur->next = walk1;
                newcur = newcur->next;
                walk1 = walk1->next;
            }
        }
        else if (walk1 == nullptr)
        {
            while (walk2)
            {
                newcur->next = walk2;
                newcur = newcur->next;
                walk2 = walk2->next;
            }
        }
        return head->next;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}