// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

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
    bool isPalindrome(ListNode *head)
    {
        if(!head || !head->next)return true;
        ListNode* ptr = head;
        vector<int> v;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i = 0; i < v.size()/2;i++)
            if(v[i] != v[v.size()-i-1])
                return false;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}