class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // v1+i + v2-j
        int n = values.size();
        vector<int> first(n), second(n);
        first[0] = values[0]+0;
        for(int i=1;i<n;i++)
            first[i] = max(first[i-1],values[i]+i);
        second[n-1] = values[n-1]-(n-1);
        for(int j=n-2;j>=0;j--)
            second[j] = max(second[j+1],values[j]-j);
        
        for(int i : first)
            cout << i << " ";
        cout << endl;

        for(int j : second)
            cout << j << " ";
        cout << endl;
        
        int maxi = 0;
        for(int i=0;i<n-1;i++)
            maxi = max(maxi,first[i]+second[i+1]);
        
        return maxi;
    }
};