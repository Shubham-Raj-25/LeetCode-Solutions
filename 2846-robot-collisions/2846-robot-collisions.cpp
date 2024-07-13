class Solution {
struct quad {
    int pos, hlth, ind;
    char dirn;
    quad(int p, char d, int h, int i) : pos(p), dirn(d), hlth(h), ind(i) {}
};

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<quad> vp;
        for (int i = 0; i < n; i++) {
            vp.emplace_back(positions[i], directions[i], healths[i], i);
        }
        sort(vp.begin(), vp.end(), [&](const quad& a, const quad& b) {
            return a.pos < b.pos;
        });

        stack<quad> st;

        for (int i = 0; i < n; i++) {
            bool canInsert = true;
            while (!st.empty() && st.top().dirn == 'R' && vp[i].dirn == 'L') {
                if (vp[i].hlth > st.top().hlth) {
                    st.pop();
                    vp[i].hlth--;
                } else if (vp[i].hlth < st.top().hlth) {
                    st.top().hlth--;
                    canInsert = false;
                    break;
                } else {
                    st.pop();
                    canInsert = false;
                    break;
                }
            }
            if (canInsert) {
                st.push(vp[i]);
            }
        }
        
        // {index, health}
        vector<pair<int, int>> temp;
        while (!st.empty()) {
            quad q = st.top();
            st.pop();
            temp.push_back({q.ind, q.hlth});
        }
        // sorting in original order
        sort(temp.begin(), temp.end());

        vector<int> ans;
        for (auto& p : temp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};