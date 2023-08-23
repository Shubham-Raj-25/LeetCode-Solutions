class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto it:s)
            mp[it]++;
        
        priority_queue<pair<int,char>> pq;

        for(auto it:mp)
            pq.push({it.second,it.first});
        
        string ans;

        while(pq.size()>1){
            auto f = pq.top();
            pq.pop();

            auto s = pq.top();
            pq.pop();

            ans += f.second;
            ans += s.second;

            f.first--;
            s.first--;

            if(f.first)
                pq.push(f);
            
            if(s.first)
                pq.push(s);
        }

        if(pq.size()==1){
            if(pq.top().first==1)
                ans += pq.top().second;
            else
                return "";
        }
        
        return ans;
    }
};