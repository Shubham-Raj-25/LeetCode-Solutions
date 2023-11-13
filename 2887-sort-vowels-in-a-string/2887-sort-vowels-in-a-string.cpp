class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e','i','o','u'};
        
        set <char> st;
        
        for(auto it:vowels)
            st.insert(it);
        
        vector<int> data;

        for(int i=0;i<s.length();i++)
            if(st.find(s[i])!=st.end())
                data.push_back(s[i]);
        
        sort(data.begin(),data.end());
        
        int i = 0;

        for(int j=0;j<s.length();j++){
            if(st.find(s[j])!=st.end())
                s[j] = data[i++];
        }
        
        return s;
    }
};