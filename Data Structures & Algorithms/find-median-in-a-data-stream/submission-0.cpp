class MedianFinder {
public:
        priority_queue<int> left;  // max heap
        priority_queue<int, vector<int>, greater<int>> right;  // min heap

        // left ele <= right elements

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        // put left's largest ele to right
        right.push(left.top());
        left.pop();

        // left size <= right size
        if(right.size() > left.size()){
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        if(left.size() > right.size()){
            return left.top();
        }else{
            return (left.top() + right.top())/ 2.0;
        }
    }
};