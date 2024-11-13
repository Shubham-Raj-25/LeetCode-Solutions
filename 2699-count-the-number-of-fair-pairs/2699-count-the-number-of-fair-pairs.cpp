class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            int l = lower - num;
            int h = upper - num;
            auto l_idx = lower_bound(nums.begin() + i+1,nums.end(), l);
            auto h_idx = upper_bound(nums.begin() + i+1,nums.end(), h);
            ans += h_idx - l_idx;
        }

        return ans;
    }
};

// nums = [0,1,7,4,4,5], lower = 3, upper = 6
//         0 -> 3 to 6 kitne element hai
//         1 -> 2 to 5 kitne element hai
//         mp[3]++ mp[7]--
//         1 -> mp[2] ++ mp[5]--
//         7 -> mp[]


// 0,4
// 0,4
// 0,5

// 1,4
// 1,4
// 1,5



// l <= a + b <= h
// l-a <= b <= h-a