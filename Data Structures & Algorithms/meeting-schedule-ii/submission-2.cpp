/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intv) {
        // find max overlapping intervals

        vector<vector<int>> events;

        for(auto &it : intv){
            events.push_back({it.start, 1});
            events.push_back({it.end, -1});
        }

        sort(events.begin(), events.end());

        int rooms = 0, ans=0;
        for(auto &e : events){
            rooms += e[1];
            ans = max(ans, rooms);
        }

        return ans;
    }
};
