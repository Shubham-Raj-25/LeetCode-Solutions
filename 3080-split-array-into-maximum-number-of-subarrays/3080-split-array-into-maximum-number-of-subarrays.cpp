class Solution {
public:
    int maxSubarrays(vector<int>& v) {
        int m=33554431;
        int n=v.size();
        for(int i=0;i<n;i++)
            m=m&v[i];
        int s=33554431;
        int c=0;
        if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                s=s&v[i];
                if(i==n-1 && s!=m)
                    return c;
                if(s==m)
                {
                    s=33554431;
                    c++;
                } 
            }
            return c;
        }
        return 1;
    }
};