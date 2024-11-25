class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string,int> mp1,mp2;
        k = s.length() / k; // len of a part;
        for(int i=0; i<s.length(); i+=k){
            string a = "";
            string b = "";
            for(int j=i;j<i+k;j++){
                a += s[j];
                b += t[j];
            }
            mp1[a]++;
            mp2[b]++;
        }
        return mp1==mp2;
    }
};