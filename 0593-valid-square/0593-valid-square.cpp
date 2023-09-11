class Solution {
public:
    bool areEqual(float a, float b){
        return abs(a-b) < 0.01;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<float> st;
        
        vector<vector<int>> p;
        
        p.push_back(p1);
        p.push_back(p2);
        p.push_back(p3);
        p.push_back(p4);

        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                float distance = sqrt(pow(p[i][0]-p[j][0],2) + pow(p[i][1]-p[j][1],2));
                st.insert(distance);
            }
        }

        // cout << st.size() << endl;
        if(st.size()!=2)
            return false;
        
        vector<float> data;

        for(auto it:st) data.push_back(it);

        sort(data.begin(),data.end());

        cout << data[0] << "  " << data[1] << endl;
        cout << (float)data[0]*sqrt(2) << endl;

        return areEqual(data[1],(float)data[0] * sqrt(2));
    }
};