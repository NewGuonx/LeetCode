// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class MyQueue
{
  public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        dq.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int i = dq.front();
        dq.pop_front();
        return i;
    }

    /** Get the front element. */
    int peek()
    {
        return dq.front();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return dq.empty();
    }
private:
    deque<int> dq;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}