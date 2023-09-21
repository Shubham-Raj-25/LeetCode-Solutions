class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> data1, data2, ans;

        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                data1.push_back(nums[i]);
            else
                data2.push_back(nums[i]);
        }

        sort(data1.begin(),data1.end());
        sort(data2.begin(),data2.end());
        reverse(data2.begin(),data2.end());

        int i = 0;

        while(i<data1.size() && i<data2.size()){
            ans.push_back(data1[i]);
            ans.push_back(data2[i]);
            i++;
        }

        while(i<data1.size()) ans.push_back(data1[i++]);

        while(i<data2.size()) ans.push_back(data2[i++]);

        return ans;

    }
};