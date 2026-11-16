class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int j = n;
        while (true) {
            int save = 0;
            while (j) {
                int digit = j % 10;
                j /= 10;
                
                save += (digit*digit); 
            }
            j = save;
            if (j == 1) {
                return true;
            }
            if (s.contains(j)) {
                return false;
            }
            s.insert(j);


        }
        
    }
};
