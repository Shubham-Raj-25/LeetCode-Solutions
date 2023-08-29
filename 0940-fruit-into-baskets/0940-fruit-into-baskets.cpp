class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        set<int> st;
        int l=0, r=0;
        int ans = 0;
        unordered_map<int,int> freq;

        while(r<fruits.size()){
            freq[fruits[r]]++;
            st.insert(fruits[r]);
            while(st.size()>2){
                // cout << st.size() << " " << freq[fruits[l]] << " " << l  << " " << r << endl;
                freq[fruits[l]]--;
                if(freq[fruits[l]]==0)
                    st.erase(fruits[l]);
                l++;
            }
            r++;

            ans = max(ans,r-l);
        }

        return ans;
    }
};