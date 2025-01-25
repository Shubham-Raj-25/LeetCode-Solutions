class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> grouping(n), groupToMin(n), ans;
        vector<pair<int,int>> data;

        for(int i=0;i<nums.size();i++){
            data.push_back({nums[i],i});
        }

        sort(data.begin(),data.end());

        int group = 0;
        
        for(int i=0;i<data.size();i++){
            int mini = i;
            grouping[data[i].second] = group;
            while(i < data.size()-1 && data[i+1].first - data[i].first <= limit){
                grouping[data[i+1].second] = group;
                i++;
            }
            groupToMin[group] = mini;
            group++;
        }

        for(int i=0;i<n;i++){
            int groupNo = grouping[i];
            int elementToPush = data[groupToMin[groupNo]].first;
            groupToMin[groupNo]++; // exhausted this element
            ans.push_back(elementToPush);
        }

        return ans;
    }
};


/*

 _____
| 3 2 1
 ------ 
3 2 1
2 3 1
1 3 2
1 2 3

9 8 4 7 (l = 2)
7 8 4 9 (Y)
8 9 4 7
7 9 4 8


DSU -> 
For each Upar -> point to the curr min val available in sorted node

*/