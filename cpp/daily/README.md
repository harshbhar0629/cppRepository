# Steps to solve Minimum window substring
```
1. Initialize n as the length of string s and m as the length of string t.
2. If m is greater than n, return an empty string since t cannot be a substring of s.
3. Create a map-Data structure to keep track of character frequencies.
4. Traverse in string t and increment each character frequency.
5. Initialize 'cnt' to m, 'start' and 'end' to 0, startIdx to -1, and len to a very large value 1e8.
6. Enter a while loop that runs until 'end' is less than n.
7. Decrement the value at map corresponding to the character at s[end]. If the result is non-negative, decrement 'cnt'.
8. Enter a nested while loop that runs as long as 'cnt' is 0.
9. Inside the nested loop, if the current window length (end - start + 1) is smaller than 'len', update 'startIdx' to 'start' and 'len' to end - start + 1.
10. Increment the value at map corresponding to the character at s[start]. If the result is positive, increment 'cnt'.
11. Increment 'start' to shrink the window from the left.
12. Increment end to expand the window from the right.
13. After exiting both loops, check if 'startIdx' is -1. If it is, return an empty string, otherwise return the substring of s starting from 'startIdx' with length 'len'.
```

# Code
```
Link: https://leetcode.com/problems/minimum-window-substring/description/

class Solution{
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();
        if(m > n){
            return "";
        }
        vector<int>map(130, 0);

        for(int i=0; i<m; i++){
            map[t[i]]++;
        }

        int cnt = m;
        int start = 0, end =0;
        int startIdx = -1, len = 1e8;

        while(end<n){
            if(--map[s[end]] >= 0){
                cnt--;
            }
            while(cnt == 0){
                if(end - start + 1 < len){
                    startIdx = start;
                    len = end-start+1;
                    // cout<<startIdx<<" "<<len<<"\n";
                }
                if(++map[s[start]] > 0){
                    cnt++;
                }
                start++;
            }
            end++;
        }

        return (startIdx == -1)? "": s.substr(startIdx, len);
    }
};
```