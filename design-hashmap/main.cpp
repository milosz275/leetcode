#include <bits/stdc++.h>

#define SIZE 100 // consider larger value, confront with overall performance for given use case

using namespace std;

class MyHashMap
{
private:
    // Hashtable. Array of lists of pairs (key, value)
    vector<list<pair<int, int>>> table;

    /**
     * Returns index of table used as hashtable with given key.
     * 
     * @param key Key to store a value.
     * @return Index of table to store data.
     */
    int hash(int key) { return key % SIZE; }

public:
    // Initialized my hashmap
    MyHashMap() : table(SIZE) {}

    /**
     * Retrieves valid list and set/appends new value with given key.
     */
    void put(int key, int value)
    {
        int h = hash(key);
        for (auto& p : table[h])
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        table[h].emplace_back(key, value);
    }

    /**
     * Retrieves value of the key.
     * 
     * @param key Key
     * @return Returns value of existent key, -1 in other case
     */
    int get(int key)
    {
        int h = hash(key);
        for (const auto& p : table[h])
            if (p.first == key)
                return p.second;
        return -1;
    }

    /**
     * Retrieves valid list and removes entry for key-value pair.
     * 
     * @param key Key for a key-value pair to remove.
     */
    void remove(int key)
    {
        int h = hash(key);
        table[h].remove_if([key](const pair<int, int>& p) { return p.first == key; });
    }
};

int main()
{
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    int value = obj->get(1);
    cout << value << endl;
    value = obj->get(3);
    cout << value << endl;
    obj->put(2, 1);
    value = obj->get(2);
    cout << value << endl;
    obj->remove(2);
    value = obj->get(2);
    cout << value << endl;
    delete obj;
}
