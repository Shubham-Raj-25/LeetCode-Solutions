class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> candidates;
        priority_queue<int,vector<int>,greater<int>> chosen;
        int j = 0;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            
            while(j < queries.size() && queries[j][0] == i)
                candidates.push(queries[j++][1]);
            
            nums[i] -= chosen.size(); // if can be made 0 by already chosen

            //if not
            while(nums[i] > 0 && candidates.size() && candidates.top() >= i){
                // we will choose it
                chosen.push(candidates.top());
                candidates.pop();
                nums[i]--;
                ans++;
            }

            if(nums[i] > 0)
                return -1;
            
            while(chosen.size() && chosen.top() <= i) // not valid anymore
                chosen.pop();

        }

        return queries.size() - ans;

    }   
};