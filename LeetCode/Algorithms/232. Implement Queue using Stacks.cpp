class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
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
        while(s1.size()>1){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int result = s1.top();
        s1.pop();
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
         while(s1.size()>1){
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int result = s1.top();
        s1.pop();
        s2.push(result);
        while(!s2.empty()){
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */