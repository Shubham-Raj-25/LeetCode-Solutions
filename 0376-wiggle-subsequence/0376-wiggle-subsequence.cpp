class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int positive = 1;
        int negative = 1;
                                            
        for(int i=1;i<nums.size();i++){
            int diff = nums[i]-nums[i-1];
            if     (diff<0) positive = max(positive,1 + negative);
            else if(diff>0) negative = max(negative,1 + positive);
        } 
        
        return max(positive,negative);

    }
};