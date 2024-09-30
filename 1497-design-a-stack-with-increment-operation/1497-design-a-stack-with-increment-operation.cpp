class CustomStack {
public:
    stack<int> st;
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st.size() == size)
            return;
        st.push(x);     
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int a = st.top();
        st.pop();
        return a;
    }
    
    void increment(int k, int val) {
    vector<int> temp;
    while(!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }
    
    for (int i = temp.size() - 1; i >= 0 && temp.size() - i <= k; i--) {
        temp[i] += val;
    }
    
    for (int i = temp.size() - 1; i >= 0; i--) {
        st.push(temp[i]);
    }
}

};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */