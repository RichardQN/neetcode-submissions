class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int n : stones){
            q.push(n);
        }
        while (q.size() > 1){
            int top = q.top();
            q.pop();
            int next = q.top();
            q.pop();
            if (top > next) {
                int temp = top - next;
                q.push(temp);
            }
        }
        q.push(0);
        return q.top();
    }
};
