class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       int n = stones.size();
        priority_queue<int> p;

        for(int n : stones){
            p.push(n);
        } 

        while(p.size() > 1){
            int y = p.top(); // heaviest
            p.pop();
            int x = p.top(); // 2nd heaviest
            p.pop();

            if( y != x){
                p.push(y-x);
            }
        }

        return p.empty() ? 0 : p.top();
    }
};