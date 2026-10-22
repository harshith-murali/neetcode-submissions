class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(begin(people), end(people));
        int s = 0 , e = n - 1;
        int cnt = 0;
        while(s <= e){
            if(people[s] + people[e] <= limit){
                s++;
                e--;
            }else {
                e--;
            }
            cnt += 1;
        }
        return cnt;
    }
};