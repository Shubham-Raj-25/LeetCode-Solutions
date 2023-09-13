class MyCircularQueue {
public:
    queue<int> q;
    int currSize = 0, maxSize = 0;
    int last;
    MyCircularQueue(int k) {
        maxSize = k;
    }
    
    bool enQueue(int value) {
        if(currSize == maxSize)
            return false;
        currSize++;
        q.push(value);
        last = value;
        return true;
    }
    
    bool deQueue() {
        if(q.empty())
            return false;
        q.pop();
        currSize --;
        return true;
    }
    
    int Front() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if(q.empty()) return -1;
        return last;
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return currSize == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */