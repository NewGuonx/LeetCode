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
        ListNode * slow = head, *fast = head , *prev = nullptr, *walk, *tmp;
        for(; fast && fast->next; prev = slow, slow = slow->next, fast = fast->next->next);
        prev->next = nullptr; // cut middle;

    	slow = reverse(slow); // reverse post half part
    	
    	walk =  head;
    	while(walk->next){
    		tmp = walk->next;
    		walk->next = slow;
    		slow = slow->next;
    		walk->next->next = tmp;
    		walk = tmp;
    	}
    	walk->next = slow;
    }
    ListNode* reverse(ListNode * head){
    	if (!head || !head->next |)
            return head;
       	ListNode * walk = head, *dummy = new ListNode(0), *tmp;
       	while(walk){
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
    ListNode *head = new ListNode(0), *p = head;
    int i = 1, n = 3;
    while (n--)
    {
        p->next = new ListNode(i);
        p = p->next;
        i++;
    }
    Solution s;
    s.reorderList(head);
    p = head;
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}