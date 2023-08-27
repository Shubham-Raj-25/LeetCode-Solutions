class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // O(n) solution
        long long f=INT_MIN,s=INT_MIN,t=INT_MIN;
        set<int> st;
        for(auto it: nums){
            st.insert(it);
            if(it>f){
                t = s;
                s = f;
                f = it;
            }

            else if(it<f && it > s){
                t = s;
                s = it;
            }

            else if(it < s && it > t)
                t = it;
        }
        if(t==INT_MIN && st.size()<=2) return f;
        return t;
    }
};