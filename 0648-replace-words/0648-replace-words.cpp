class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        unordered_set<string> st;
        
        for(auto word:dictionary)
            st.insert(word);

        string ans;

        for(int i=0;i<sentence.size();i++){
            string temp = "";
            while(i<sentence.size() && sentence[i]!=' '){
                temp += sentence[i];
                if(st.find(temp)!=st.end())
                    break;
                i++;
            }

            ans += temp+" ";    
            while(i<sentence.size() && sentence[i]!=' ') i++;
        }
        if(ans.length()!=0) ans.pop_back();
        return ans;
    }
};