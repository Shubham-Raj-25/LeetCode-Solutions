class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(auto it:candyType)
            st.insert(it);
        return min((int)candyType.size()/2,(int)st.size());
    }
};