class MyHashSet {
public:
    int M;
    vector<list<int>> buckets;
    MyHashSet() {
        M = 10001;
        buckets = vector<list<int>>(M, list<int>{});
    }
    int getIndex(int key){
        return key % M;
    }
    
    void add(int key) {
        int idx = getIndex(key);
        auto itr = find(begin(buckets[idx]), end(buckets[idx]), key);
        if(itr == buckets[idx].end()){
            buckets[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = getIndex(key);
        auto itr = find(begin(buckets[idx]), end(buckets[idx]), key);
        if(itr != buckets[idx].end()){
            buckets[idx].erase(itr);
        }
    }
    
    bool contains(int key) {
        int idx = getIndex(key);
        auto itr = find(begin(buckets[idx]), end(buckets[idx]), key);
        if(itr != buckets[idx].end()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */