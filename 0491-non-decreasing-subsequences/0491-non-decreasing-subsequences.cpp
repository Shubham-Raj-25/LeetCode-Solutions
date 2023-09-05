class Solution {
public:
    // maybe no need of memoiation

    void func(int idx,int last, vector<int>& nums, set<vector<int>>& st, vector<int>& temp){
        
        if(temp.size()>1)
            st.insert(temp);

        if(idx==nums.size())
            return;
        
        // skip
        func(idx+1,last,nums,st,temp);

        //take
        if(nums[idx] >= last){
            temp.push_back(nums[idx]);
            func(idx+1,nums[idx],nums,st,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        set<vector<int>> st;
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        
        func(0,-101,nums,st,temp);
        
        for(auto it:st)
            ans.push_back(it);

        return ans;
    }
};