class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        deque<int> minQ,maxQ;
        int left=0,right=0,ans=1;
        while(right<nums.size()){
            while(!minQ.empty() && minQ.back()>nums[right]){
                minQ.pop_back();
            }
            while(!maxQ.empty() && maxQ.back()<nums[right]){
                maxQ.pop_back();
            }
            minQ.push_back(nums[right]);
            maxQ.push_back(nums[right]);
            if(abs(minQ.front()-maxQ.front())>limit){
                if(minQ.front()==nums[left])minQ.pop_front();
                if(maxQ.front()==nums[left])maxQ.pop_front();
                left++;
            }else{
                ans=max(ans,right-left+1);
            }
            right++;
        }
        return ans;
    }
};