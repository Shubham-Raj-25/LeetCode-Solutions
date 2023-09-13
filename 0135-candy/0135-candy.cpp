class Solution {
public:
    int candy(vector<int>& ratings) {
        // start at minimum positions
        int n = ratings.size();
        int sum = 0;
        vector<int> candies(n,1);
        // Left to right traversal
        // takes care of the left neighbor
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])
                candies[i] = candies[i-1]+1;
        
        // Right to left traversal
        // takes care of the right neighbor
        for(int i=n-2;i>=0;i--)
            {
                if(ratings[i]>ratings[i+1])
                    candies[i] = max(candies[i],candies[i+1]+1);
                sum += candies[i];
            }
        
        sum += candies[n-1];
        
        return sum;
        
    }
};