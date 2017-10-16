class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x;
        while (1) {
            x = q1.front();
            q1.pop();
            if (q1.empty()) {
                swap(q1, q2);
                return x;
            }
            q2.push(x);
        }
    }
    
    /** Get the top element. */
    int top() {
        int x;
        while (!q1.empty()) {
            x = q1.front();
            q2.push(x);
            q1.pop();
        }
        swap(q1, q2);
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1;
    queue<int> q2;
};