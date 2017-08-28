//
// Created by daniel.yyf on 2017/8/14.
//

#include "iostream"
#include "unordered_map"
#include "list"

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {
    }

    int get(int key) {
        UMIP::iterator it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value) {
        UMIP::iterator it = cache.find(key);
        if (it != cache.end()) {
            touch(it);
        } else {
            if(cache.size()==_capacity){
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key]={value,used.begin()};
    }


    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> UMIP;
private:
    void touch(UMIP::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    int _capacity;
    LI used;
    UMIP cache;


};


