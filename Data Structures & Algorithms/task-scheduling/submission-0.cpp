class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        priority_queue<int> pq;
        for (int count : freq) {
            if (count > 0) {
                pq.push(count);
            }
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                }
            }

            for (int f : temp) {
                if (f > 0) {
                    pq.push(f);
                }
            }

            time += pq.empty() ? temp.size() : cycle;
        }

        return time;
    }
};