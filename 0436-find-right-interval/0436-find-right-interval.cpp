class Solution {
public:
    int bs(int a, vector<vector<int>>& data) {
        int l = 0;
        int r = data.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (data[mid][0] >= a)
                r = mid;
            else
                l = mid + 1;
        }

        return (l == r && data[l][0] >= a) ? l : -1;
    }

    vector<int> findRightInterval(vector<vector<int>>& data) {
        map<vector<int>, int> mp;

        for (int i = 0; i < data.size(); i++)
            mp[data[i]] = i;

        sort(data.begin(), data.end());

        int n = data.size();

        vector<int> ans(n, -1);

        for (int i = 0; i < data.size(); i++) {
            int idx = bs(data[i][1], data);
            if (idx != -1)
                ans[mp[data[i]]] = mp[data[idx]];
        }

        return ans;
    }
};
