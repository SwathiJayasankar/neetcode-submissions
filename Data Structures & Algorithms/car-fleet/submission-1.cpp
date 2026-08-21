class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,double>> cars;
        
        // if a car takes lesser or equal time than the car front of it to reach target - it joins the fleet. else if it take more time, it forms another fleet

        // its only dep on position (nearest to dest), time req

        for(int i=0; i<n; i++){
            double time = (double)(target - position[i])/ speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend());

        stack<double> st;
        for(int i=0; i<n; i++){
            double time = cars[i].second;

            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};
