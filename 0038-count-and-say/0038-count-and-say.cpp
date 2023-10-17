class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string data = countAndSay(n-1);
        char prev = data[0];
        string ans;
        for(int i=0;i<data.length();i++){
            int count = 0;
            while(i<data.length() && data[i]==prev)
                {count++;
                i++;}
            ans += (to_string(count)+prev);
            
            if(i<data.length())
                {
                    prev = data[i];
                    i--;
                }
        }

        return ans;
    }
};