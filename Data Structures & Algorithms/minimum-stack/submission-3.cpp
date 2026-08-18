class MinStack {
    stack<long> st;
    long minVal;

   public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(0);
            minVal = val;
        } else {
            st.push(val - minVal);
            if (val < minVal) minVal = val;
        }
    }

    void pop() {
        if (!st.empty()) {
            long x = st.top();
            st.pop();
            if (x < 0) minVal = minVal - x;
        }
    }

    int top() {
        long x = st.top();
        if (0 < x)
            return x + minVal;
        else
            return (int)minVal;
    }

    int getMin() { return (int)minVal; }
};
