// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

class Solution {
public:
    string minWindow(string s, string t) {
        
        int len1 = s.size();
        int len2 = t.size();
        if(len2 > len1) return "";

        int count =0;
        int start =0;
        int ansStart =-1;
        int ansEnd = INT_MAX;
        unordered_map<char ,int> smp;
        unordered_map<char,int> tmp;

        for(auto ch: t){
            // store freq of finding string
            tmp[ch]++;
        }

        for(int i=0;i<len1;i++){
            
            char ch = s[i];
            smp[ch]++;
            // for valid character
            if(smp[ch] <= tmp[ch]) count++;

            // if count is equal to the finding string then it holds all character of that string
            if(count==len2){

                // shrink the window
                while(smp[s[start]] > tmp[s[start]] || tmp[s[start]] == 0){

                    // remove or decrease the freq of invalid character
                    if(smp[s[start]] > tmp[s[start]])
                        smp[s[start]]--;
                    start++;
                }

                // find length of window in which it hold all character of finding string
                int windowLength = i - start + 1;
                if(ansEnd > windowLength){
                    ansStart = start;
                    ansEnd = windowLength;
                }
            }
        }
        // if we don't find any window that hold all character of finding string then eeturn empty string
        if(ansStart == -1) return "";

        return s.substr(ansStart,ansEnd);
    }
};