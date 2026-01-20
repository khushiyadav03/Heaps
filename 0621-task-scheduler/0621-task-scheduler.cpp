class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char t : tasks){
            freq[t]++;
        }

        priority_queue<int> pq;
        for(auto it : freq){
            pq.push(it.second);
        }

        int time = 0;

        while(!pq.empty()){
            int cycle = n+1;
            vector<int> temp;

            while(cycle>0 && !pq.empty()){
                int f = pq.top();
                pq.pop();

                f--;
                if(f>0){
                    temp.push_back(f);
                }

                time++;
                cycle--;
            }

            for(int f : temp){
                pq.push(f);
            }

            // agr heap empty nhi h toh idle time add karo
            if(!pq.empty()){
                time += cycle;
            }
        }
        return time;
    }
};