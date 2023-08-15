class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = 1e9;
        set<int> st;

        for(int i=x;i<nums.size();i++){
            st.insert(nums[i-x]);
            auto it = st.upper_bound(nums[i]);
            
            if(it != st.end())
                ans = min(ans, abs(*it - nums[i]));
            
            if(it != st.begin())
                ans = min(ans, abs(*prev(it)-nums[i]));
        }
        
        return ans;
    }
};