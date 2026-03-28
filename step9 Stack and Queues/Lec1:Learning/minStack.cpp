#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

class MinStack {
    stack<pair<int, int>> st; // ✅ declare as member variable

public:
    MinStack() {
        // no need to declare st again here
    }

    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else {
            int mini = min(st.top().second, val);
            st.push({val, mini});
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
