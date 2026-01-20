class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(auto &t : tasks){
            count[t - 'A']++;
        }

        // sabse jyada freq task sabse aage aa jayega
        sort(begin(count), end(count), greater<int>());

        // sabse max freq vala task
        int maxFreq = count[0];

        int gap = maxFreq - 1;
        int idleSlots = gap * n;

        for(int i = 1; i<26; i++){
            if(count[i] == 0) continue;

            // ek task max ik baar har gap me aa sakta h 
            // so min(count[i], gap) subtract karte h
            idleSlots -= min(count[i], gap);
        }

        // agr abhi bhi idle slots bachhe h
        if(idleSlots > 0){
            // tottal time = tasks + idle time
            return tasks.size() + idleSlots;
        }

        return tasks.size(); // no idle 
    }
};