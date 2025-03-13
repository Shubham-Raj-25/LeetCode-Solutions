class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int mid) { // O(N)
        vector<int> inc(nums.size()+1,0);
        int curr_max_dec = 0;
        for(int i=0;i<mid;i++){
            auto q = queries[i];
            inc[q[0]] += q[2];
            inc[q[1]+1] -= q[2];
        }
        
        for(int i=0;i<nums.size();i++){
            curr_max_dec += inc[i];
            if(nums[i] > curr_max_dec)
                return false;
        }
        
        return true;
        
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         Binary Search on Answer Space?  -> TC : log(N) * (O(k) + O(N)) = Nlog(N)
        int low = 0, high = queries.size();
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(isZeroArray(nums,queries,mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return ans;
    }
};