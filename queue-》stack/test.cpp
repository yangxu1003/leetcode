class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = q.size();
        size--;//保证最后留一个元素
        while(size--)
        {
            q.push(q.front());//将队列头部的元素转移到后面
            q.pop();
        }

        int result = q.front();
        q.pop();//头删
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

    queue<int> q;
};