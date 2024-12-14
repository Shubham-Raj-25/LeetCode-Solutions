class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // Sliding window and set+map or better yet Multiset
        multiset<int> st;
        int l = 0;
        long long ans = 0;

        for(int r=0;r<nums.size();r++){
            st.insert(nums[r]);
            int mini = *st.begin();
            int maxi = *prev(st.end());
            while(abs(mini-maxi) > 2){
                st.erase(st.find(nums[l]));
                l++;
                mini = *st.begin();
                maxi = *prev(st.end());
            }
            ans += r - l + 1;
        }

        return ans;

    }
};