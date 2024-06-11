class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp1, mp2;
        vector<int> ans;

        for(auto it: arr2)
            mp2[it]++;
        for(auto it: arr1)
            mp1[it]++;
        
        for(auto it: arr2){
            for(int i=0;i<mp1[it];i++){
                ans.push_back(it);
            }
        }

        int k = ans.size();

        for(auto it: mp1){
            if(mp2.find(it.first) == mp2.end()){
                for(int i=0;i<it.second;i++){
                    ans.push_back(it.first);
                }
            }
        }

        sort(ans.begin() + k, ans.end());

        return ans;
    }       
};