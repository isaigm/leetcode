// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
      
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int y = 0;
        bool _delete = true;
        util(0, y, _delete);
        return y;
    }
    
    /** Get the front element. */
    int peek() {
        int y = 0;
        bool _delete = false;

        util(0, y, _delete);
        return y;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
    void util(int x, int &y, bool &_delete)
    {
        if(!s1.empty())
        {
            x = s1.top();
            s1.pop();
            if(s1.empty())
            {
                y = x;
            }
            util(x, y, _delete);
            if(s1.empty() && _delete) 
            {
                _delete = false;
                return;
            }
            s1.push(x);
        }
    }
    std::stack<int> s1;

};



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */