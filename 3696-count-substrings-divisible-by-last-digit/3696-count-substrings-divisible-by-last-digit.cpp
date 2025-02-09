class Solution {
public:
    long long countSubstrings(string s) {
        long long ans = 0;
        int n = s.length();
        
        // index, divisor, reminder
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(10,vector<int>(10,0)));

        for(int i=1; i<= n; i++){
            int digit = s[i-1]-'0';
            for(int divisor = 1; divisor <= 9; divisor++){
                for(int reminder = 0; reminder < divisor; reminder++){
                    dp[i][divisor][(reminder*10+digit)%divisor] += dp[i-1][divisor][reminder];
                }
                dp[i][divisor][digit%divisor]++;
            }
            ans += dp[i][digit][0];
        }

        return ans;
    }
};

/*

1 <= s.length <= 10^5

You are given a string s consisting of digits.

Return the number of substrings of s divisible by their non-zero last digit.

A substring is a contiguous non-empty sequence of characters within a string.

Note: A substring may contain leading zeros.


12936

1
2 12
9 29 129
3 93 293 1293
6 36 936 2936 12936

dp[i] = dp[]

1     2  9   3  6
12       93  36
1293     936
12936

---
go from right to left

last digit 1->9
1 divides all
2 divedes even (all)
3 divedes recursive sum = 3 (do a sw) // or keep a sum [HARD] -> keep a track of sum and if sum%3 == 0
4 divides last two devisible by 4 (last 2 check if yes then all divislble otherwise none)
5 divdes 0,5
6 -> 2 & 3                                      [HARD]
7 -> if not prime and isn'tdivisble by other numbers   [HARD]
8 -> last 3 digit either 0s or divisble or 8   
9 -> if sum divisble by 9                       [HARD]


5701283


* * * * * * 
  2     2

The above is a hectic solution and people have worked to solve this using moduls operations
but a dp solution is much better


-> we need complete divisibility => reminder 0
-> we can divide a substr by it's end num only
-> we need to do it on O(N) time only => need to reuse previous calculations

123 ---> 1234
123 / 3  ||  1234 / 4

-> division possible from 1 to 9
-> reminder possible from 1 to 9

-> try all possible divisions

oldNum ---> oldNumNewNum
-------     -------------
  mod            mod

oldNum % mod = rem.  || (oldNum*10 + newNum) % mod => rem*10 + newNum%mod

i->i+1
dp[i+1][num][rem*10+digit%mod] += dp[i][num][rem]

+1 for the digit/rem

dp[i][num][rem] -> 


*/ 