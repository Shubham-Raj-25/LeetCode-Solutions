class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int len=0,idx=-1;
        for(int i=0;i<s.length();i++){
            char x=s[i];
            if(x>='0' && x<='9'){
                len*=(x-'0');
            }else{
                len+=1;
            }
            if(len>=k){
                idx=i;
                break;
            }
        }
        for(int i=idx;i>=0;i--){
            char x=s[i];
            if(x>='0' && x<='9'){
                len/=(x-'0');
                k%=len;
                if(k==0)k=len;
            }else{
                if(len==k){
                    string ans;
                    ans+=x;
                    return ans;
                }
                len-=1;
            }
        }
        return "";
    }
    
};