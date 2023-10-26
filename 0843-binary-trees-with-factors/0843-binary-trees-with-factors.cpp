class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a){
        unordered_map<int,int> s;
        int mod=1e9+7;
        sort(a.begin(),a.end());
        for(auto x:a)s[x]=1;
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]%a[j]==0){
                    if(s.find(a[i]/a[j])!=s.end()){
                        long long temp=(long long )s[a[j]]*s[a[i]/a[j]];
                        s[a[i]]=(s[a[i]]+temp)%mod;
                    }
                }
            }
        }
        int ans=0;
        
        for(auto x: s) ans=(ans%mod+x.second%mod)%mod;
        return ans;
    }
};