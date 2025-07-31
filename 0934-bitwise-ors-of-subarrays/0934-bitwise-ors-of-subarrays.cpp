class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>oris;
        unordered_set<int>curr,prev;
        for(auto it:arr){
            curr.clear();
            curr.insert(it);
            for(auto it2:prev){
                curr.insert(it|it2);
            }
            prev=curr;
            for(auto it2:prev){
                oris.insert(it2);
            }
        }
        return oris.size();
    }
};