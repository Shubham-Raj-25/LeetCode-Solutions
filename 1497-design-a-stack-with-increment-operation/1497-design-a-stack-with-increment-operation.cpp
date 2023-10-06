class CustomStack {
public:
    vector<int> data;
    int idx = 0;
    unordered_map<int,int> inc;

    CustomStack(int maxSize) {
     vector<int> temp(maxSize,-1);
     data = temp;  
    }
    
    void push(int x) {
        if(idx==data.size())
            return ;
        data[idx] = x;
        idx++;
    }
    
    int pop() {
        idx--;
        if(idx<0){
            idx=0;
            return -1;}
        int increment = inc[idx];
        inc[idx] = 0;
        inc[idx-1] += increment;
        return data[idx]+increment;
    }
    
    void increment(int k, int val) {
        k = min(k,idx);
        inc[k-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */