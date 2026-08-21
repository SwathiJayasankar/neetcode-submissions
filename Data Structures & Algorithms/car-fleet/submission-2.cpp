class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> cars;
        
        // if a car takes lesser or equal time than the car front of it to reach target - it joins the fleet. else if it take more time, it forms another fleet

        // its only dep on position (nearest to dest), time req

        for(int i=0; i<n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        double maxtime = 0;     //time of the fleet in front of cur car
        int fleets= 0;

        for(auto car : cars){
            int pos = car.first;
            int speed = car.second;

            double time = (double)(target - pos)/speed;

            if(time > maxtime){
                fleets++;
                maxtime = time;
            }
        }

        return fleets;
  
    }
};
