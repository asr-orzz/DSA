#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:

    stack<long long> st;
    long long minElement;

    MinStack() {
    }

    void push(int x) {

        if (st.empty()) {
            st.push(x);
            minElement = x;
        }

        else if (x >= minElement) {
            st.push(x);
        }

        else {
            // x is the new minimum
            st.push(2LL * x - minElement);
            minElement = x;
        }
    }

    void pop() {

        if (st.empty()) {
            return;
        }

        long long x = st.top();
        st.pop();

        // encoded value means current min was changed
        if (x < minElement) {
            minElement = 2LL * minElement - x;
        }
    }

    int top() {

        if (st.empty()) {
            return -1;
        }

        long long x = st.top();

        // encoded value -> actual top is minElement
        if (x < minElement) {
            return minElement;
        }

        return x;
    }

    int getMin() {

        if (st.empty()) {
            return -1;
        }

        return minElement;
    }
};