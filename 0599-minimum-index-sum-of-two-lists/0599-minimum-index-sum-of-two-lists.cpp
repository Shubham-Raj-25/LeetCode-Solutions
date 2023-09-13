class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        set<pair<string,int>> st;
        int mini = INT_MAX;
        for(int i=0;i<list1.size();i++){
            for(int j=0;j<list2.size();j++){
                if(list1[i]==list2[j]){
                    st.insert({list1[i],i+j});
                    mini = min(mini,i+j);
                }
            }
        }

        vector<string> ans;
        for(auto it:st)
            if(it.second==mini)
                ans.push_back(it.first);

        return ans;
    }
};