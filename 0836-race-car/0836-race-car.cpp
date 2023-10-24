#define ll long long
class Solution {
public:
    int racecar(int target) {
        queue<pair<int,pair<ll,ll>>>q;
        set<pair<ll,ll>> vis;
        q.push({0,{0,1}}); // {moves,{pos,speed}}

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int moves = front.first;
            ll pos = front.second.first;
            ll speed = front.second.second;

            if(pos == target)
                return moves;
            
            if(vis.find({pos,speed})!=vis.end()) continue;

            vis.insert({pos,speed});

            // for A

            q.push({moves+1,{pos+speed,speed*2}});

            // for R

            if((pos+speed > target && speed > 0)|| (pos+speed < target and speed < 0)){
                if(speed > 0)
                    q.push({moves+1,{pos,-1}});
                else
                    q.push({moves+1,{pos,1}});
            }
        }

        return -1;

    }
};