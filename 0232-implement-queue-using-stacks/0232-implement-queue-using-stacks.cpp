class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        if (in.empty())
        {
            while (!out.empty())
            {
                in.push(out.top());
                out.pop();
            }
        }
        in.push(x);
        if (in.size() == 1) front = x;
    }

    int pop() {
        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }
        int num = out.top();
        out.pop();
        if (!out.empty()) front = out.top();
        return num;
    }

    int peek() {
        return front;
    }

    bool empty() {
        return in.empty() && out.empty();
    }

    int front;
    stack<int> in;
    stack<int> out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */