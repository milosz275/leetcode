#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (max_heap.empty() || num <= max_heap.top())
        {
            cout << "adding " << num << " to max heap" << endl;
            max_heap.push(num);
        }
        else
        {
            cout << "adding " << num << " to min heap" << endl;
            min_heap.push(num);
        }

        // balancing heaps
        if (max_heap.size() > min_heap.size() + 1) 
        {
            cout << "moving " << max_heap.top() << " from max to min heap" << endl; 
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size())
        {
            cout << "moving " << min_heap.top() << " from min to max heap" << endl; 
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian()
    {
        if (max_heap.size() == min_heap.size())
            return (max_heap.top() + min_heap.top()) / 2.0;
        else
            return max_heap.top();
    }
};

int main()
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    cout << param_2 << endl;
    obj->addNum(3);
    param_2 = obj->findMedian();
    cout << param_2 << endl;
    delete obj;
    return 0;
}
