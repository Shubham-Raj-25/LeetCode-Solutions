class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> st;
        int i=1;
        int ans = 0;
        while(n){
            if(st.find(k-i)==st.end()){
                st.insert(i);
                ans += i;
                i++;
                n--;
            }
            else
                i++;
        }

        return ans;
    }
};