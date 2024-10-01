class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k,0);
        
        for(int i : arr)
            freq[((i%k)+k)%k]++;
        
        bool ans = true;

        for(int i=1;i<k;i++)
            if(freq[i] != freq[k-i])
                ans = false;

        if(freq[0] % 2 !=0)
            ans = false;

        return ans;
    }
};