class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto [x1, ch1] = pq.top(); pq.pop();

            if (res.size() > 1 && res.back() == ch1 && res[res.size() - 2] == ch1) {
                if (pq.empty()) break;

                auto [x2, ch2] = pq.top(); pq.pop();
                res += ch2;
                if (--x2 > 0) pq.push({x2, ch2});

                pq.push({x1, ch1});
            } else {
                res += ch1;
                if (--x1 > 0) pq.push({x1, ch1});
            }
        }
        return res;
    }
};