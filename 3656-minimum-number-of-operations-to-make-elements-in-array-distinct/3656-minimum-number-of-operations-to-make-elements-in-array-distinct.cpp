class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.count(nums[i])){
                return ceil((float)(i+1)/3);
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};

/*

* * * * * * * * * * 
            <-------

*/ 