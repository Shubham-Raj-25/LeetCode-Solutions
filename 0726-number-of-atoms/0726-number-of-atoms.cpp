class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<int,pair<string,int>> mp; // {idx, {char,count}}
        stack <int> st; // indexes of "("

        for(int i=0;i<formula.length();i++){
            if(isupper(formula[i])){
                string element = "";
                element += formula[i];
                int idx = i;
                while(i < formula.length()-1 && islower(formula[i+1]))
                    element += formula[++i];
                int count = 0;
                while(i < formula.length()-1 && isdigit(formula[i+1]))
                    count = count * 10 + int(formula[++i]) - 48;
                mp[idx] = {element,max(1,count)};
                cout << "Count of " << element << " is " << max(1,count) << endl;
                
            }else if(formula[i] == '('){
                st.push(i);
            }else if(formula[i] == ')'){
                int start_idx = st.top(), end_idx = i;
                st.pop();
                int multiplier = 0;
                while(i < formula.length()-1 && isdigit(formula[i+1]))
                    multiplier = multiplier * 10 + int(formula[++i]) - 48;
                for(int k=start_idx;k<=end_idx;k++){
                    if(mp.find(k) != mp.end()){
                        mp[k] = {mp[k].first,mp[k].second*max(1,multiplier)};
                    }
                }
            }
        }

        map<string,int> mp2;
        
        for(auto it: mp)
            mp2[it.second.first] += it.second.second;
        
        string ans = "";

        for(auto it: mp2){
            cout << it.first << " -- " << it.second << endl; 
            ans += it.first;
            if(it.second>1)
                ans += to_string(it.second);
        }
        
        return ans;
    }
};