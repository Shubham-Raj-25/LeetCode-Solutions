class Solution {
public:
    vector<long long> monotise(vector<int>& A){
        stack<pair<long long,int>> st;
        vector<long long> res;
        long long r = 0;

        for(int i=0;i<A.size();i++){
            long long num = A[i];
            int k = i;
            while(st.size() && st.top().first>num){
                auto p = st.top();
                st.pop();
                int j = st.size() ? st.top().second : -1;
                r -= p.first*(p.second-j);
            }
            int j = st.size() ? st.top().second : -1;
            r += (i-j)*num;
            st.push({num,i});
            res.push_back(r);
        }

        return res;

    }

    long long maximumSumOfHeights(vector<int>& maxHeights) {
        vector<long long> l2r = monotise(maxHeights);
        reverse(maxHeights.begin(),maxHeights.end());
        vector<long long> r2l = monotise(maxHeights);
        reverse(maxHeights.begin(),maxHeights.end());
        reverse(r2l.begin(),r2l.end());
        long long ans = -1;
        for(int i=0;i<l2r.size();i++)
            ans = max(ans,l2r[i]+r2l[i]-maxHeights[i]);
        return ans;
    }
};