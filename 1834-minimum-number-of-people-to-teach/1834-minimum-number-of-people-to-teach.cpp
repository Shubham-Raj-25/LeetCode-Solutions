class Solution {
public:
    int minimumTeachings(int n,vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSet(m + 1);

        for (int i = 0; i < m; ++i) {
            for (int lang : languages[i]) {
                langSet[i + 1].insert(lang);
            }
        }

        vector<pair<int, int>> needLanguage;
        for (const auto& friendship : friendships) {
            int u = friendship[0];
            int v = friendship[1];
            if (!haveCommonLanguage(langSet[u], langSet[v])) {
                needLanguage.push_back({u,v});
            }
        }

        if (needLanguage.empty()) {
            return 0;
        }

        int minUsers = m;
        for (int lang = 1; lang <= n; ++lang) {
            unordered_set<int> usersToTeach;
            for (const auto& pair : needLanguage) {
                int u = pair.first;
                int v = pair.second;
                if (langSet[u].find(lang) == langSet[u].end()) {
                    usersToTeach.insert(u);
                }
                if (langSet[v].find(lang) == langSet[v].end()) {
                    usersToTeach.insert(v);
                }
            }
            minUsers = min(minUsers, static_cast<int>(usersToTeach.size()));
        }

        return minUsers;
    }

private:
    bool haveCommonLanguage(unordered_set<int>& set1,unordered_set<int>& set2) {
        for (int lang : set1) {
            if (set2.count(lang) > 0) {
                return true;
            }
        }
        return false;
    }
};