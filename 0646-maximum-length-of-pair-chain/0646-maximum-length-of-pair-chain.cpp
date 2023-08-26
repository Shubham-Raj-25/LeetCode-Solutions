class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
     // greedy try
     sort(pairs.begin(),pairs.end(), cmp);
     
     for(auto it:pairs)
        cout << it[0] << " " << it[1] << endl;

     int curr = INT_MIN;
     int ans = 0;
     for(auto it: pairs){
         if(it[0] > curr){
             ans++;
             curr = it[1];
         }
     }

     return ans;
    }

    private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
};