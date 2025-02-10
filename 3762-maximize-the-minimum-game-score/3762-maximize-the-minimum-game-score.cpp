class Solution {
public:
    bool isPossible(vector<int>& points, long long m, long long toReach){
        int n = points.size();
        vector<long long> gameScore(n,0);
        
        for(int i=0; i<n; i++){
            long long curr = gameScore[i];
            if(curr >= toReach && i == n-1){
                break;
            }
            curr += points[i];
            m--;
            if(curr >= toReach){
                continue;
            }
            // long long jumpsNeeded = ceil(float(toReach-curr)/points[i]);
            long long jumpsNeeded = (toReach - curr + points[i] - 1) / points[i];

            // cout << 
            m -=  2*jumpsNeeded;
            if(m < 0){
                return false;
            }
            if(i != n-1){
                gameScore[i+1] = (long long)jumpsNeeded * points[i+1];
            }
        }

        return m >= 0;
    }

    long long maxScore(vector<int>& points, int m) {
        // maximize minimum value
        // T T T T T T T T F F F F F F F F (figure out the last true)

        long long low = 0, high = 1e15;

        while(low + 1 < high){
            long long mid = low + (high-low)/2;
            // cout << "mid is " << mid << endl;
            if(isPossible(points,m,mid)){
                // cout << "POSSIBLE!!" << endl;
                low = mid;
            }
            else{
                // cout << "XXXX" << endl;
                high = mid;
            }
        }
        return low;
    }
};

/*

points : n
m moves
gameScore
gameScore[i] == 0 for all i.

You can make at most m moves.

Increase the index by 1 and add points[i] to gameScore[i].
Decrease the index by 1 and add points[i] to gameScore[i].

maximum possible minimum value in gameScore after at most m moves.

2 <= n == points.length <= 5 * 104
1 <= points[i] <= 10^6
1 <= m <= 10^9 :-> simulation not possibe -> no dp?

1 2 3 (m = 5)
-----
0 0 0
1 2 3 (m = 2 left)

2 4 3 (m = 0 left)

2 4
0 0 (m = 3)
2 4 (m = 1 left)
4 4 

100 100 100 1 (m = 7)

100 100 100 1
100 100 200 2

min value + distance + flip-flop

1 100 100 100 100 100 100 m = 

1 increment to the min will consume 2 m's

1 5 5 5 1  (m = 20)

1 5 5 5 1  (m = 15 left)

equally distribute
4 distance ->  11 left ceil(11/2) increments left = 6 increments -> 3 3

sparsed 1

5 5 5 1 5 5 5 5 1 5 5 5 1 5 5 5 5 1

paired 1s (no /2 required)

group min values
take distances + flip flops

1 2 2 2 1 2 2 2 1 (m = 100)


bs on answer space

mid?

points : 5 b c d e f g h
gameSc : 0 0 0 0 0 0 0 0 
mid = 100
  
*/ 
