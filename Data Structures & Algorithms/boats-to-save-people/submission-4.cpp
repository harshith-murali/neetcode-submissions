class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int boats = 0;
        
        while (i <= j) {
            // If the lightest and heaviest person can share a boat
            if (people[i] + people[j] <= limit) {
                i++;
            }
            // Heaviest person always gets a boat (either alone or paired)
            j--;
            boats++;
        }
        
        return boats;
    }
};