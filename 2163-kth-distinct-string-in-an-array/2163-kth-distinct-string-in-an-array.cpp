class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> freq;
        for(auto it : arr)
            freq[it]++;
        for(auto it: arr){
            k -= freq[it] == 1;
            if(!k)
                return it;
        }
        return "";
    }
};