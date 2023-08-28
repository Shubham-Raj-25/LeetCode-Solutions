class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        q2=q1;
    }
    
    int pop() {
        // empty the queue then copy elements from other queue untill only 1 is left
        while(!q1.empty())
            q1.pop();
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();
        }
        int k = q2.front();
        q2.pop();
        q2 = q1;
        return k;
    }
    
    int top() {
        while(q2.size()!=1)
            q2.pop();

        int k = q2.front();
        q2 = q1;
        return k;        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */