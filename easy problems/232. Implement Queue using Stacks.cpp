class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!data.empty()) {
            d.push(data.top());
            data.pop();
        }
        int x = d.top();
        d.pop();
        while (!d.empty()) {
            data.push(d.top());
            d.pop();
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        while (!data.empty()) {
            d.push(data.top());
            data.pop();
        }
        int x = d.top();
        while (!d.empty()) {
            data.push(d.top());
            d.pop();
        }
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
    }
private:
    stack<int> data;
    stack<int> d;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */