class Solution {
public:
    int mini = INT_MAX;
    int maxi = INT_MIN;

    // Recursive function to simulate each round
    void solve(vector<int> &arr, int r, int& F, int& S) {
        int n = arr.size();
        int Newsize = n / 2;

        bool f1 = false;
        bool f2 = false;

        // Check if F and S face each other this round
        for (int i = 0; i < Newsize; i++) {
            if ((arr[i] == F && arr[n - i - 1] == S) || 
                (arr[i] == S && arr[n - i - 1] == F)) {
                mini = min(mini, r);
                maxi = max(maxi, r);
            }
        }

        // Check if both F and S are still in the game
        for (int i = 0; i < n; i++) {
            if (arr[i] == F) f1 = true;
            if (arr[i] == S) f2 = true;
        }

        if (!f1 || !f2) return; // One of them is eliminated

        // Generate all possible match outcomes for next round
        vector<int> newarr(Newsize + (n % 2));
        int upto = (1 << Newsize); // 2^Newsize combinations

        for (int i = 0; i < upto; i++) {
            int l = 0;
            int right = newarr.size() - 1;

            for (int j = 0; j < Newsize; j++) {
                // If bit j is set, pick left player; else right
                if ((1 << j) & i) {
                    newarr[l++] = arr[j];
                } else {
                    newarr[right--] = arr[n - j - 1];
                }
            }

            // If odd number of players, middle one advances automatically
            if (n % 2) {
                newarr[right] = arr[n / 2];
            }

            // Recursive call for next round
            solve(newarr, r + 1, F, S);
        }
    }

    // Entry point: builds initial array and starts simulation
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> arr(n);
        for (int i = 1; i <= n; i++) {
            arr[i - 1] = i;
        }

        solve(arr, 1, firstPlayer, secondPlayer);

        return {mini, maxi}; // Return earliest and latest round
    }
};
// to check if first player nad second player will face off in knouckout match we muct stimulate a;; match outcomes.depending or how many matches are resolved in each round , the matchup between the 2 players can ouccur earlier or later 
    //stimulate all possible outcomes recursively for each round 
        //1. check if firstplayer and 2nd player are playing agianst each other
        //if not ,stimulate next round with all combinations of winner from each pair
        //use bitmasking to stimule all valid match results(choose left or right winner)
        //store min max round where players meet (1st and 2nd players)