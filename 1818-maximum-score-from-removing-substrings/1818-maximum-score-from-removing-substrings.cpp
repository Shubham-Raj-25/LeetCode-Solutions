class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // dp times out, stack greedy??
        stack<char> st;
        int ans = 0;
        char top, curr;
        if(x >= y){
            top  = 'a';
            curr = 'b';
        }
        else{
            top  = 'b';
            curr = 'a';
        }

        for(auto it: s){
            if(!st.empty() && it == curr && st.top() == top){
                st.pop();
                ans += max(x,y);
            }
            else
                st.push(it);
        }

        string new_s = "";
        
        while(st.size()){
            new_s += st.top();
            st.pop();
        }

        for(int i=new_s.length()-1; i>=0; i--){
            if(!st.empty() && new_s[i] == top && st.top() == curr){
                st.pop();
                ans += min(x,y);
            }
            else
                st.push(new_s[i]);
        }
        
        return ans;
        
}};