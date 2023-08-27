class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<long long> pq;
        set<long long> st;
        for(auto it:nums){
            if(st.find(it)!=st.end())
                continue;
            st.insert(it);
            pq.push(it);
        }   

        if(pq.size()<3)
            return pq.top();
        
        for(int i=0;i<2;i++)
            pq.pop();
        
        return pq.top();

    }
};