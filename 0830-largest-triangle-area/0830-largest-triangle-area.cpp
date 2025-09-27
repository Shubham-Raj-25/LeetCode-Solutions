class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // S=12[x1(y2−y3)+x2(y3−y1)+x3(y1−y2)]
        double ans = 0.0;
        for(int i=0;i<points.size();i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                for(int k=j+1;k<points.size();k++){
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    double area= (double)abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2.0;
                    // cout<<area << endl;
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};