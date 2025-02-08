class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int maxWidth = 0;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[st.top()] > nums[i]){
                st.push(i);
            }
        }

        for(int i=nums.size()-1;i >=0;i--){
            while(st.size() && nums[st.top()] <= nums[i]){
                maxWidth = max(maxWidth,i-st.top());
                st.pop();
            }
        }

        return maxWidth;
    }
};