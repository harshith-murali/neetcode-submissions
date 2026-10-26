class MyHashMap {
public:
    vector<list<pair<int,int>>> buckets;
    int size = 100000;
    MyHashMap() {
        buckets.resize(size);
    }
    int getBucket(int key){
        return key % size;
    }
    void put(int key, int value) {
        int bucket_no = getBucket(key);
        auto &chain = buckets[bucket_no];
        for(auto &it : chain){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        chain.push_back({key,value});
    }
    
    int get(int key) {
        int bucket_no = getBucket(key);
        auto &chain = buckets[bucket_no];
        for(auto &it : chain){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket_no = getBucket(key);
        auto &chain = buckets[bucket_no];
        for(auto it = chain.begin(); it != chain.end(); it++){
            if(it->first == key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */