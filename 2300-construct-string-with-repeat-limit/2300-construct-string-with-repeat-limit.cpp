class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int> freq;
        priority_queue<pair<char,int>> pq;
        string ans = "";
        for(char c : s){
            freq[c]++;
        }

        for(auto it: freq){
            pq.emplace(it.first,it.second);
        }

        while(pq.size()){
            auto [curr,f] = pq.top();
            pq.pop();

            for(int i=0;i<min(repeatLimit,f);i++){
                ans += curr;
            }

            f -= min(repeatLimit,f);

            if(f > 0){
                if(pq.size()){
                    auto [next, f_next] = pq.top();
                    pq.pop();

                    ans += next;
                    f_next--;

                    if(f_next > 0){
                        pq.emplace(next,f_next);
                    }

                }else{
                    break;
                }
                pq.emplace(curr,f);
            }
        }

        return ans;
    }
};