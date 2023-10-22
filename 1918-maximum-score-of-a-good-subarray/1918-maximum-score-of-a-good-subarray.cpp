class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], mini = nums[k];
        int i = k, j = k;

        while(1){
            // move left or right
            if( i== 0 && j == nums.size()-1)
                break;
            
            // cout << i << " " << j << " " << endl;

            // always move right
            if(i==0 && j<nums.size()-1){
                j++;
                mini = min(mini,nums[j]);               
            }
            else if(j==nums.size()-1 && i>0){ // always move left
                i--;
                mini = min(mini,nums[i]);            }
            else if(i>0 && j<nums.size()-1){
                if(nums[j+1] > nums[i-1])
                    {
                        j++;
                        mini = min(mini,nums[j]);
                    }
                else if(nums[i-1] > nums[j+1])
                    {
                        i--;
                        mini = min(mini,nums[i]);
                    }
                else{
                    j++;
                        mini = min(mini,nums[j]);
                    i--;
                        mini = min(mini,nums[i]);
                }
            }
            ans = max(ans,mini*(j-i+1));

        }

        return ans;
    }
};