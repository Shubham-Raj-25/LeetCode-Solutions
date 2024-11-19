class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_set<int> st;
        unordered_map<int,int> mp;
        int l = 0;
        long long curr_sum = 0;
        
        for(int i=0;i<k;i++){
            curr_sum += nums[i];
            st.insert(nums[i]);
            mp[nums[i]]++;
        }

        if(st.size() == k)
            ans = curr_sum;
        
        for(int r=k;r<nums.size();r++){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0)
                st.erase(nums[l]);
            curr_sum -= nums[l];
            l++;
            
            st.insert(nums[r]);
            mp[nums[r]]++;
            curr_sum += nums[r];
            
            if(st.size() == k)
                if(curr_sum > ans)
                    ans = curr_sum;
        }

        return ans;
    }
};