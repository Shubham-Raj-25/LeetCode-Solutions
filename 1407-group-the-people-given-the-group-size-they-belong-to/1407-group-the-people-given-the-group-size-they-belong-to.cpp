class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        // O(n2) solution
        
        int n = g.size();
        
        vector<vector<int>> ans;
            
        for(int size=1;size<=n;size++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(g[i]!=size) continue;
                if(temp.size()==size){
                    ans.push_back(temp);
                    temp.clear();
                }
                temp.push_back(i);
            }
            if(temp.size()==size)
                ans.push_back(temp); 
        }

        return ans;
    }
};