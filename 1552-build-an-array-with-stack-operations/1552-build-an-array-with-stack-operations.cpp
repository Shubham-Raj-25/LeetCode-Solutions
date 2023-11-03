class Solution { //push pop push push push
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int idx = 0;

        for(int i=1;i<=n;i++){
            if(i==target[idx]){ 
                idx++;
                ans.push_back("Push");
                }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(idx==target.size()) break;
        }

        return ans;
    }
};