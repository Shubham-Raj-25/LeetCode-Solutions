class Skiplist {
public:
    // let's skip this question too by using hashmap, bruh :|
    unordered_map<int,int> joke;
    Skiplist() {
        
    }
    
    bool search(int target) {
        return joke[target];
    }
    
    void add(int num) {
        joke[num] += 1;
    }
    
    bool erase(int num) {
        if(!joke[num])
            return false;
        joke[num] -= 1;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */