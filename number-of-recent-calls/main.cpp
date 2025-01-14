#include <bits/stdc++.h>

using namespace std;

class RecentCounter 
{
private:
    queue<int> recents;
public:
    RecentCounter() : recents() {}
    
    int ping(int t)
    {
        recents.push(t);
        while (!recents.empty() && recents.front() < t - 3000)
            recents.pop();
        return recents.size();
    }
};

int main()
{
    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << endl;
    cout << obj->ping(100) << endl;
    cout << obj->ping(3001) << endl;
    cout << obj->ping(3002) << endl;
    delete obj;
    return 0;
}
