class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxFreq = 0;

        for(char c : tasks){
            freq[c - 'A']++;
            maxFreq = max(maxFreq, freq[c- 'A']);
        }
        int cntmaxF = 0;
        for(int f : freq){
            if(f == maxFreq) cntmaxF++;
        }

        int x = (maxFreq-1)*(n+1) + cntmaxF;

        if(tasks.size() > x){
            return tasks.size();
        }
        return x;
    }
};
