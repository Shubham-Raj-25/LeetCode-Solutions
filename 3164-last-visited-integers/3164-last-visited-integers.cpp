class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans, int_so_far;

        for(int i=0;i<words.size();i++){
            if(words[i]!="prev")
                int_so_far.push_back(stoi(words[i]));
            else{
                int k = 0;
                while(i<words.size() && words[i]=="prev"){
                    k++;
                    if(k>int_so_far.size())
                        ans.push_back(-1);
                    else
                        ans.push_back(int_so_far[(int)int_so_far.size()-k]);
                    i++;
                }
                i--;
            }
        }

        return ans;
    }
};