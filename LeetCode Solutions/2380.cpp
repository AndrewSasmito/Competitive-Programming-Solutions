class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int cnt = 0, start;
        while (true){
            start = cnt;
            for (int i = s.size() - 1; i >= 1; --i){
                if (s[i] == '1' && s[i - 1] == '0'){
                    ++cnt;
                    for (int j = 0; j < s.size(); ++j){
                        if (s[j] == '0' && s[j + 1] == '1'){
                            swap(s[j], s[j + 1]);   
                            ++j;
                        }
                    }
                }
            }
            if (start == cnt){
                return cnt;
            }
        }

    }
};
