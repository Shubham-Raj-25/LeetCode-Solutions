class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // nums[i] - i = nums[j] - j;
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        
        mp[nums.back()-(n-1)]++;
        
        for(int i=n-2;i>=0;i--){
            int cnt = mp[nums[i]-i];
            ans += (n-1-i-cnt);
            mp[nums[i]-i]++;
        }

        return ans;
    }
};


/*

i < j and j - i != nums[j] - nums[i].

nums[j] = nums[i]-i + j
nums[j] - j = nums[i]-i;

 i j
[4,1,3,3]
 4 0 1 0 
 4-0 = 4

good pairs - total pairs?

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

*/ 