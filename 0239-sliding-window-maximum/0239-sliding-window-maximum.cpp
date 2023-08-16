class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<int> pq;

        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        
        vector<int> ans;
        ans.push_back(pq.top());
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]++;
            pq.push(nums[i]);
            while(mp.find(pq.top())!=mp.end() && mp[pq.top()]>0)
                {   
                    mp[pq.top()]--;
                    pq.pop();
                }
            ans.push_back(pq.top());
        }

        return ans;
    }
};