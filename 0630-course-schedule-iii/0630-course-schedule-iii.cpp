class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1] ;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),cmp);
        
        priority_queue<int> pq;

        int time = 0;

        for(auto it: courses){
            time += it[0];
            pq.push(it[0]);

            if(time > it[1]){
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};