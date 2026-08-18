class MedianFinder {
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;

   public:
    MedianFinder() {}

    void addNum(int num) {
        smallHeap.push(num);

        if (largeHeap.size() > 0 && smallHeap.top() > largeHeap.top()) {
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }

        if (smallHeap.size() > largeHeap.size() + 1) {
            int val = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(val);
        }

        if (largeHeap.size() > smallHeap.size() + 1) {
            int val = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(val);
        }
    }

    double findMedian() {
        if (smallHeap.size() > largeHeap.size()) {
            return (double)smallHeap.top();
        } else if (largeHeap.size() > smallHeap.size()) {
            return (double)largeHeap.top();
        } else
            return (double)(smallHeap.top() + largeHeap.top()) / 2;
    }
};
