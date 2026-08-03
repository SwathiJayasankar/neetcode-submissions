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
    bool canAttendMeetings(vector<Interval>& intv) {
        sort(intv.begin(), intv.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        for(int i=1; i<intv.size(); i++){
            if(intv[i].start < intv[i-1].end){
                return false;
            }
        }
        return true;
    }
};
