class NumberContainers {
private:
    unordered_map<int,int> indexToNum;
    unordered_map<int,set<int>> numToIndexes;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexToNum.find(index) != indexToNum.end()){ // O(1)
            int prevNum = indexToNum[index];
            numToIndexes[prevNum].erase(index); // O(logN)
        }
        indexToNum[index] = number;
        numToIndexes[number].insert(index); // O(logN)
    }
    
    int find(int number) {
        if(numToIndexes[number].size() == 0){
            return -1;
        }
        return *numToIndexes[number].begin(); // O(1)
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */


/*

mp[idx->num]
mp[num->indexes] (sorted order)
1 <= index, number <= 109
At most 105 calls will be made in total to change and find.

unordered_map<idx,num>
unordered_map<num,ordered_set<indexes>>
*/ 