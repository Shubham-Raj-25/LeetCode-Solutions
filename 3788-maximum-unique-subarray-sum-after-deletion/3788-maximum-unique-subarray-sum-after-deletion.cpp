class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int sum=0;
        int maxi=INT_MIN;
        for(auto it:nums)
        {
            if(it>0)
            st.insert(it);
            else
            {
                maxi=max(maxi,it);
            }
        }
        for(auto it: st)
        {
            
            sum+=it;
        }
        if(st.size()==0)
        return maxi;
        else
        return sum;
    }
};