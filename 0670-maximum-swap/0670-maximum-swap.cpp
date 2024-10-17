class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string p = s;
        sort(p.rbegin(),p.rend());
        for(int i=0;i<s.length();i++){
            if(s[i] != p[i]){
                int k;
                for(int j=i+1;j<s.length();j++){
                    if(p[i] == s[j]){
                       k = j;
                    }
                }
                swap(s[i],s[k]);
                return stoi(s);
            }
        }
        return num;
    }
};