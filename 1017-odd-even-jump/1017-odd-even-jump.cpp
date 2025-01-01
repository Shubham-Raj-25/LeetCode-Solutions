class Solution {
public:
    static bool customComparison(pair<int,int> a, pair<int,int> b)
    {   
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }

    bool helper(int curr, bool isOdd,int n, vector<int>& oddJump, vector<int>& evenJump,vector<vector<int>>& dp){
        if(curr == n-1){
            return true;
        }

        if(dp[curr][isOdd] != -1){
            return dp[curr][isOdd];
        }
        
        bool isPossible = false;

        if(isOdd && oddJump[curr] != -1){
            isPossible = helper(oddJump[curr],false,n,oddJump,evenJump,dp);
        }
        else if(!isOdd && evenJump[curr] != -1){
            isPossible = helper(evenJump[curr],true,n,oddJump,evenJump,dp);
        }

        return dp[curr][isOdd] = isPossible;
    }

    int oddEvenJumps(vector<int>& arr) {
        // stack + recursion with 2 states
        int n = arr.size();
        vector<pair<int,int>> data;
        vector<int> oddJump(n,-1), evenJump(n,-1);
        stack<int> st;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            data.push_back({arr[i],i});
        }

        sort(data.begin(),data.end()); // NLogN

        for(auto it : data){
            int curr = it.second;
            while(st.size() && curr > st.top()){
                int idx = st.top();
                st.pop();
                oddJump[idx] = curr;
            }
            st.push(curr);
        }
        
        stack<int> st2;
        st = st2;

        sort(data.begin(),data.end(),customComparison);
        for(auto it : data){
            int curr = it.second;
            while(st.size() && curr > st.top()){
                int idx = st.top();
                st.pop();
                evenJump[idx] = curr;
            }
            st.push(curr);
        }

        for(int i=0;i<arr.size();i++){
            if(helper(i,true,n,oddJump,evenJump,dp)){
                ans++;
            }
        }

        return ans;
    }
};