// sliding window question most probably
// O(n2) will also work
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int ans = 0;
        for(int n : nums)
            st.insert(n);

        int discEle = st.size();

        for(int i=0;i<nums.size();i++){
            st.clear();
            st.insert(nums[i]);
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                if(st.size()==discEle)
                    ans++;
            }
        }

        return ans;
    }
};