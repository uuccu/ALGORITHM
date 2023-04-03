class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = people.size();

        sort(people.begin(), people.end());

        int temp = people.size() - 1;

        for (int i = 0; i < people.size(); i++) {
            int cur = people[i];
            for (int j = temp; j >= 0; j--) {
                if (i >= j) break;
                int pmax = people[j];
                if (cur + pmax <= limit) {
                    temp = j - 1;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};