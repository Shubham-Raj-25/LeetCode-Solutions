class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, sum = 0;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            sum += nums[r];
            while(sum * (r-l+1) >= k){
                sum -= nums[l];
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
};

/*

score => sum * len
as elements are >0
as len increases score will increase

if a subarray has score < k
all of it's subarray will have score < k

sliding window + shrink as soon as score > k 
               & shrink till score is < k


* * * * * * * *
_     _

1 -> 1
2 -> 3
3 -> 6

(n * n+1)/ 2

*/ 