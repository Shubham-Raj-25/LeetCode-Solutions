// Can't be solved by Two Pointers approach as there are negative elements in the array
// we need to use deque data structure to simulate a similar effect
// credit = tech Dose
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long,long long>> dq; //{index,sum}
        long long sum = 0;
        long long ans = INT_MAX;

        for(long long i=0;i<nums.size();i++){
            sum += nums[i];

            if(sum>=k) ans = min(ans,i+1); // here just simply taking sum from start,removal will happen later

            // if possible, try to compress the window from left/front of deque
            pair<long long, long long> curr = {INT_MIN,INT_MIN};

            while(dq.size() && (sum-dq.front().second>=k)){
                curr = dq.front();
                dq.pop_front();
            }   

            // lets see if there is any new possible ans
            if(curr.second!=INT_MIN) ans = min(i-curr.first,ans);

            // while pushing make sure to maintain the monotonically increasing order of deque
            while(dq.size() && sum<=dq.back().second) dq.pop_back();

            dq.push_back({i,sum});
                
        }

        return ans == INT_MAX ? -1: ans;
    }
};