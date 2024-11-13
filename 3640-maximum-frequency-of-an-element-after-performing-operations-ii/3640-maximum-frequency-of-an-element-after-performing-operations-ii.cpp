class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> og_freq;
        map<int,int> mp;
        set<int> points;
        int curr_freq = 0, max_freq = 1;

        for(auto it: nums){
            og_freq[it]++;
            mp[it-k]++;
            mp[it+k+1]--;
            points.insert(it);
            points.insert(it-k);
            points.insert(it+k+1);
        }

        for(auto it: points){
            curr_freq += mp[it];
            max_freq = max(max_freq, og_freq[it] + min(numOperations, curr_freq - og_freq[it]));
        }

        return max_freq;
    }
};