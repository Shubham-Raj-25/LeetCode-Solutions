class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> ans;

        for(int i=0;i<n;i++) dp[i][i] = nums[i];

        for(int l = 2; l <=n; l++){
            for(int s=0; s < n - l + 1; s++){
                int e = s + l - 1;
                dp[s][e] = dp[s][e-1] ^ dp[s+1][e];
            }
        }

        for(int l=2; l <=n; l ++){
            for(int s=0; s < n - l + 1; s++){
                int e = s + l - 1;
                dp[s][e] = max(dp[s][e],(int)max(dp[s][e-1],dp[s+1][e]));
            }
        }

        for(auto query : queries){
            ans.push_back(dp[query[0]][query[1]]);
        }

        return ans;
    }   
};

/*

nums n
XOR score of any subarray of nums[li..ri].

2,8,4,32,16,1

2,8,4
2^8,8^4
2^8^8^4
2^4

endpoint only?

a b c d
a^b,b^c,c^d
a^b^b^c,b^c^c^d
a^c^b^d

ab
a^b

abc
a^b,b^c
a^b^b^c
a^c

abcde
a^b,b^c,c^d,d^e
a^c,b^d,c^e
a^e

odd -> first and last
even -> all

[2,8,4]

1 <= n == nums.length <= 2000
precompute:
    O(n^2)
1 <= q == queries.length <= 10^5

10^5 * 2000 ? -> 2*10^7?

2,8,4,32,16,1
maxXor -> 
    even -> all 
        keep taking running

    odd -> first and last

get score of every subsstring [i....j]

now when query says [i..j]

abcde

a^b,b^c,c^d,d^e
a^b^b^c,b^c^c^d,c^d^d^e
= a^c,b^d,c^e
a^c^b^d^b^d^c^e
a^e
* * * *


abcdef
(ab) a^b
(abc) a^c
(abcd) a^b^c^d
(abcde) a^e
(abcdef) a^b^c^d^e^f

abcdef
 ---

dp[1][3] = dp[0][2] ^ dp[0][3]
         = a^c ^ a^b^c^d
         = b^d
*/ 