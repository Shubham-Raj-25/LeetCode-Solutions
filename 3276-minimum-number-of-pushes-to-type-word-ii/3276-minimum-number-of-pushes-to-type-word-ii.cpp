class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(auto it: word)
            freq[it-'a']++;
        
        sort(freq.rbegin(), freq.rend());

        int len = 1, count = 0, ans = 0;

        for(auto it : freq){
            if(!it)
                break;
            if(count == 8){ // total 8 buttons are there
                len++;
                count = 0;
            }
            ans += it * len;
            count++;
        }

        return ans;
    }
};