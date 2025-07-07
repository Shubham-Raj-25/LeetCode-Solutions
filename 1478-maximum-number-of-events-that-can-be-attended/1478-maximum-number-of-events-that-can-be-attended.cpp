class Solution {
private:
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int eventCount = 0, currDay = 1;
        for(int i=0;i<events.size();){
            currDay = max(currDay,events[i][0]);
            while(i<events.size() && events[i][0] <= currDay){
                pq.push(events[i][1]);
                i++;
            }
            while(pq.size() && pq.top() < currDay){
                pq.pop();
            }
            while(pq.size()){
                currDay++;
                eventCount++;
                pq.pop();
                while(i<events.size() && events[i][0] <= currDay){
                    pq.push(events[i][1]);
                    i++;
                }
                while(pq.size() && pq.top() < currDay){
                    pq.pop();
                }   
            }
        }

        return eventCount;
    }
};

/*

s <= d <= e
1 d -> 1 ev

greedy won't work

[[1,2],[2,3],[3,4],[1,2]]


1-0
2-3
3-1
4-2

[2,2]
[2,100]

sort by increasing last day?

[1,2],[1,2],[2,3],[3,4][1,100]

[154,154][150,155][150,155][150,155]
[150,155][150,155][150,155][154,154]

[[1,2],[2,3],[3,4],[1,2]]
[[1,2],[1,2],[2,3],[3,4]]

    ----------
          --
    ----------


track: currDay (to invalidate the events), eventsDone

1. sort by increasing last day
2. iterate over the array
3. increase currDay and eventDone if attended an event
4. while(i.endDate < currDate) i++

the above approach is wrong

simple sorting seems might work

[[1,2],[1,2],[3,3],[1,5],[1,5]]

[1,2][1,2][1,5][1,5][3,3]

for all the valid possible events,
consume the one with least end data


put all consumable events in min heap with end data
\


till currDay D



events : [si, ei]


*/ 