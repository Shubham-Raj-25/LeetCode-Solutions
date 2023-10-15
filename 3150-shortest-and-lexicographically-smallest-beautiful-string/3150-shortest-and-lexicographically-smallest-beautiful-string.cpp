class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int c=0;
        string ans="";
        vector<string>vect;
        int m=101;
        
        for(int i=0;i<s.size();i++){
            ans="";
            c=0;
            for(int j=i;j<s.size();j++){
                ans+=s[j];
                if(s[j]=='1'){
                    c++;
                }
                if(c>=k){
                    m=min(m,j-i+1);
                    vect.push_back(ans);
                }
            }
        }
        
        sort(vect.begin(),vect.end());
        for(auto ele:vect){
            if(ele.size()==m){
                return ele;
            }
        }
        return "";
    }
};