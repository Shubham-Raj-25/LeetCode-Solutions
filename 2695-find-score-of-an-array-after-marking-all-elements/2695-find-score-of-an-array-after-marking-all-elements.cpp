class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(int i=0;i<nums.size();i++)
            pq.push({nums[i],i});
        
        while(pq.size()){
            int ele = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(nums[idx] == -1) // marked
                continue;
            ans += ele;
            nums[idx] = -1;
            if(idx > 0 )
                nums[idx-1] = -1;
            if(idx < nums.size()-1)
                nums[idx+1] = -1;
        }

        return ans;
    }
};