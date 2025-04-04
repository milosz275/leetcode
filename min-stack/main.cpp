#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
    stack<int, deque<int>> s;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    MinStack() : s(), q() {}
    
    void push(int val)
    {
        s.push(val);
        q.push(val);
    }
    
    void pop()
    {
        if (s.empty() || q.empty())
        {
            if (s.empty())
                throw runtime_error("min-stack.pop: empty stack");
            else
                throw runtime_error("min-stack.pop: empty priority queue");
            return;
        }
        int el = s.top();
        queue<int> temp;
        while (!q.empty() && q.top() != el)
        {
            temp.push(q.top());
            q.pop();
        }
        if (!q.empty())
        {
            q.pop();
            while (!temp.empty())
            {
                q.push(temp.front());
                temp.pop();
            }
        }
        s.pop();
    }
    
    int top()
    {
        if (s.empty() || q.empty())
        {
            if (s.empty())
                throw runtime_error("min-stack.top: empty stack");
            else
                throw runtime_error("min-stack.top: empty priority queue");
            return -1;
        }
        return s.top();
    }
    
    int getMin()
    {
        if (s.empty() || q.empty())
        {
            if (s.empty())
                throw runtime_error("min-stack.getMin: empty stack");
            else
                throw runtime_error("min-stack.getMin: empty priority queue");
        }
        return q.top();
    }
};
    
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
    
int main()
{
    try
    {
        unique_ptr<MinStack> s(make_unique<MinStack>());
        s->push(-2);
        s->push(0);
        s->push(-3);
        cout << "min: " << s->getMin() << '\n';
        s->pop();
        cout << "top: " << s->top() << '\n';
        cout << "min: " << s->getMin() << '\n';
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}
