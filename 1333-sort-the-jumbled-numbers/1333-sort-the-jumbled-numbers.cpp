class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> data;
        for(int i=0;i<nums.size();i++){
            string num = to_string(nums[i]);
            reverse(num.begin(),num.end());
            int to_insert=0;
            int digit = 1;
            for(char i : num){
                to_insert += digit * mapping[int(i)-48];
                digit *= 10;
            }
            data.push_back({to_insert,i});
        }
        sort(data.begin(),data.end());
        vector<int> ans;
        for(auto it: data)
            ans.push_back(nums[it.second]);
        return ans;
    }
};