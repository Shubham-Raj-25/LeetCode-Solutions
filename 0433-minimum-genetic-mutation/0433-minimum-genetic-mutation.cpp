class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st;
        for(auto it:bank)
            st.insert(it);
        
        queue<pair<string,int>> q;

        set<string> vis;
        
        char data[4] = {'A','C','G','T'};

        q.push({startGene,0});

        vis.insert(startGene);

        while(!q.empty()){
            string str = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(str == endGene)
                return dist;
            
            for(int i=0;i<4;i++){
                for(int j=0;j<8;j++){
                    if(str[j]==data[i])
                        continue;
                    char temp = str[j];

                    str[j] = data[i];
                    if(st.find(str)!=st.end() && vis.find(str)==vis.end()){
                        vis.insert(str);
                        q.push({str,dist+1});
                    }

                    str[j] = temp;
                }   
            }
        }

        return -1;
    }
};