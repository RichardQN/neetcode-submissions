class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int l = 0, r = 0, i = 0,  retLen = 0;
        for (int r = 0; r < s.size(); r++){
            if (s[r] == t[i]){
                retLen++;
                if (i < t.size()){
                    i++;
                } else {
                    break;
                }
            }
        }
        /*while (r < s.size()){
            if (s[r] == t[0]){
                int i = 0;
                l = r;
                while (s[r] == t[i] && r < s.size() && i < t.size()){
                    r++;
                    i++;
                }
                retLen = max(r-l, retLen);
            }
            r++;
            
        }*/
        cout<<retLen;
        if (retLen == t.size()){
            return 0;
        } else if (retLen == 0){
            return t.size();
        } else {
            return t.size() - retLen;
        }

       
    }
};