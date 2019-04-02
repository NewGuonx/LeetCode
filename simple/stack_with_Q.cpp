// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class MyStack
{
  public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int i = q.back();
        q.pop_back();
        return i;
    }

    /** Get the top element. */
    int top()
    {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
    deque<int> q;
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}