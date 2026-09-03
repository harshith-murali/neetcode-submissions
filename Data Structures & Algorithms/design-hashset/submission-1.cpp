class MyHashSet {
public:
    int M;
    vector<list<int>> buckets;

    int getIndex(int key) {
        return key % M;
    }

    MyHashSet() {
        M = 10001;
        buckets = vector<list<int>>(M, list<int>{});
    }
    
    void add(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        if (itr == buckets[index].end()) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        if (itr != buckets[index].end()) {
            buckets[index].erase(itr);
        }
    }
    
    bool contains(int key) {
        int index = getIndex(key);
        auto itr = find(buckets[index].begin(), buckets[index].end(), key);
        return itr != buckets[index].end();
    }
};