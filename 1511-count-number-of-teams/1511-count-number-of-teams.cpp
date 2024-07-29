class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int result = 0;

        for (int i = 0; i < n; ++i) {
            int leftSmaller = 0, rightGreater = 0;
            int leftGreater = 0, rightSmaller = 0;

            for (int j = 0; j < i; ++j) {
                if (rating[j] < rating[i]) leftSmaller++;
                if (rating[j] > rating[i]) leftGreater++;
            }

            for (int k = i + 1; k < n; ++k) {
                if (rating[k] > rating[i]) rightGreater++;
                if (rating[k] < rating[i]) rightSmaller++;
            }

            result += leftSmaller * rightGreater; // Increasing triplets
            result += leftGreater * rightSmaller; // Decreasing triplets
        }

        return result;
    }
};
