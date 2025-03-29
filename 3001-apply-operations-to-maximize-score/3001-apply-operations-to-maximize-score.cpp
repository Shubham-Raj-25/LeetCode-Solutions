class Solution {
public:
    const int MOD = 1e9 + 7;
    int primeScore(int n) {
        int count = 0;
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) count++;
        return count;
    }

    long long power(long long a, long long x) {
        long long res = 1;

        
        while (x > 0) { 
            if (x % 2 == 1) {
                res = ((res * a) % MOD);
            }
 
            a = (a * a) % MOD;
            x /= 2;
        }

        return res;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>s(n);
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        vector<long long>ranges(n);

        for(int i = 0;i<n;i++){
            s[i] = primeScore(nums[i]);
        }

       for (int i = 0; i < n; i++) {
            while (!st.empty() && s[st.top()] < s[i]) {
                st.pop();
            }
            left[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
 
        while (!st.empty()) st.pop();
 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && s[st.top()] <= s[i]) {
                st.pop();
            }
            right[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }



        for(int i = 0;i<n;i++){
            ranges[i] = (long long)(i-left[i]) * (long long)(right[i] - i);
        }

        priority_queue<pair<int,int>>pq;
        for(int i = 0;i<n;i++){
            pq.push({nums[i],i});
        }

        long long ans = 1 ;
        while(k>0){
            auto [num,idx] = pq.top();
            pq.pop();

            if(ranges[idx] == 0) continue;
            long long op = min((long long)k,ranges[idx]);

            ans = (ans*power(num,op)) % MOD;
            k -= op;
        }
        return ans;
    }
};