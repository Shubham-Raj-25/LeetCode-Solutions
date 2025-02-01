class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        int n = nums.size();
        int j = n-1, i = n - 1;
        long long ans = 0;
        long long operations = 0; 

        while(i >= 0){
            // inserting i
            int popCount = 0;
            while(dq.size() > 0 && dq.back().first <= nums[i]){
                popCount += dq.back().second;
                operations += (long long) (nums[i] - dq.back().first) * (long long) dq.back().second;
                dq.pop_back();
            }
            dq.push_back({nums[i],popCount+1});

            if(operations <= (long long) k){
                ans += (long long) (j-i+1);
            }
            else{ // move j, shrink window
                while(i < j && operations > (long long) k){
                    auto frnt = dq.front();
                    dq.pop_front();
                    operations -= (long long)(frnt.first - nums[j]);
                    frnt.second--;
                    if(frnt.second != 0){
                        dq.push_front(frnt);
                    }
                    j--;
                }

                if(operations <= (long long) k){
                    ans += (long long) (j-i+1);
                }
            }

            i--;
        }

        return ans;
    }
};

/*

nums n k
each subarray: k operations (increase by 1)

Note that each subarray is considered independently,
meaning changes made to one subarray do not persist to another.

non-decreasing

n(n+1)/2

[6 5 5 3 5 5 5 5 5 5 5]  (k=7)
k = 7
1
7 - 5 = 2

[1 3 3 1 2 1 5 2 1 4] k = 4
15 + 10 + 

[6,3,1,2,4,4] (k=7)
multiset

[6,3,1,3,6], k = 4
2 + 10
maximum so far

updating deficiet in O(1)

  i     j
6 3 1 2 4 (k=4)

{(4,1)} l = 1
{(2,1),(4,1)} l = 1 + 2
{(1,1),(2,1),(4,1)} l = 1 + 2 + 3
op=1*2 + 1*1 = 3
{(3,3),(4,1)}
{()}

*/ 