class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros,ones;
        int count = 0;
        for(auto it: s){
            if(it == '0')
                count++;
            zeros.push_back(count);
        }

        count = 0;

        for(int i=s.length()-1;i>=0;i--){
            ones.push_back(count);
            if(s[i] == '1')
                count++;
        }

        reverse(ones.begin(),ones.end());
        
        int ans = 0;

        for(int i=0;i<ones.size()-1;i++)
            ans = max(ans, ones[i] + zeros[i]);
        
        return ans;
    }
};