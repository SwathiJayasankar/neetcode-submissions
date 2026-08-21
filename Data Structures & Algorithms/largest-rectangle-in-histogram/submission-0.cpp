class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        int n = hts.size();

        stack<int> st;
        vector<int> nse(n,n);
        // if nse dosent exist, it is n
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && hts[i] <= hts[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        vector<int> pse(n,-1);
        for(int i=0; i<n; i++){
            while(!st.empty() && hts[i] <= hts[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i=0; i<n; i++){
            int b = nse[i] - pse[i] -1;
            int area = hts[i]*b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
