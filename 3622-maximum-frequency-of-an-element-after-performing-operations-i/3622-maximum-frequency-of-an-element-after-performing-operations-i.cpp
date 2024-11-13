class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int,int> mp;
        int freq=0,max_freq = 1;
        set<int> points;
        unordered_map<int,int> og_freq;

        for(int num: nums){
            mp[num-k]++;
            mp[num+k+1]--;
            og_freq[num]++;
            points.insert(num-k);
            points.insert(num);
            points.insert(num+k+1);
        }

        for(auto it : points){
            freq += mp[it];
            max_freq = max(max_freq, og_freq[it]+ min(numOperations, freq - og_freq[it]));
        }

        return max_freq;
    }
};