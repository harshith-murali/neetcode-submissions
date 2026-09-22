class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq; 
    // frequency -> {key, value, frequency}

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key) {
        auto &vec = *(mp[key]);

        int value = vec[1];
        int f = vec[2];

        // Remove from old frequency list
        freq[f].erase(mp[key]);

        if (freq[f].empty()) {
            freq.erase(f);
        }

        // Increase frequency
        f++;

        // Add to new frequency list
        freq[f].push_front({key, value, f});

        // Update iterator
        mp[key] = freq[f].begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        int value = (*(mp[key]))[1];

        makeMostFrequentlyUsed(key);

        return value;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        // Key already exists
        if (mp.find(key) != mp.end()) {

            auto &vec = *(mp[key]);
            vec[1] = value;

            makeMostFrequentlyUsed(key);

        }
        // Space available
        else if (size < cap) {

            size++;

            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();

        }
        // Cache full
        else {

            // Lowest frequency
            auto &elementToRemove = freq.begin()->second;

            // Remove LRU from lowest-frequency list
            int key_to_delete = elementToRemove.back()[0];

            elementToRemove.pop_back();

            if (elementToRemove.empty()) {
                freq.erase(freq.begin());
            }

            // Remove from hashmap
            mp.erase(key_to_delete);

            // Insert new key with frequency 1
            freq[1].push_front({key, value, 1});
            mp[key] = freq[1].begin();
        }
    }
};