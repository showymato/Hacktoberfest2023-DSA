#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int csize;

public:
    LRUCache(int capacity) : csize(capacity) {}

    void refer(int key) {
        if (ma.find(key) == ma.end()) {
            if (dq.size() == csize) {
                int last = dq.back();
                dq.pop_back();
                ma.erase(last);
            }
        } else {
            dq.erase(ma[key]);
        }
        dq.push_front(key);
        ma[key] = dq.begin();
    }

    void display() {
        for (auto it = dq.begin(); it != dq.end(); ++it) {
            cout << (*it) << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache ca(4);
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    return 0;
}
