class Solution {
public:
    string reorganizeString(string ans) {
      
        vector<int>v(26,0);
        int count =0,letter =0;
        for(int i=0;i<ans.size();i++){
           
            v[ans[i]-'a']++;
            if(count<v[ans[i]-'a']){
                count = v[ans[i]-'a'];
                letter = ans[i]-'a';
            }
        }
       
        if(count > (ans.size()+1)/2) return "";
        int index =0;
       
        while(v[letter]!=0){
           
            ans[index] = char(letter+'a');
            index+=2;
            v[letter]--;
        }

        for(int i=0;i<26;i++){
           
            while(v[i]>0){
              
                if(index>=ans.size()){
                    index =1;
                }
                ans[index] = char(i+'a');
                index+=2;
                v[i]--;
            }
        }

        return ans;
    }
};



class Solution {
public:
    string reorganizeString(string ans) {
      
        vector<int>v(26,0);
        int count =0;
        for(int i=0;i<ans.size();i++){
           
            v[ans[i]-'a']++;
            if(count<v[ans[i]-'a']){
                count = v[ans[i]-'a'];
            }
        }
       
        if(count > (ans.size()+1)/2) return "";
        priority_queue<pair<int,char>>pq;

        for(int i=0;i<26;i++){
            if(v[i]) { 
                char ch = i+'a';
                pq.push({v[i],ch});
            }
        }
       
        string answer("");

        while(pq.size()>1){
            pair<int,char> it = pq.top();
            pq.pop();
            pair<int,char> itr = pq.top();
            pq.pop();
            answer +=it.second;
            answer +=itr.second; 

            it.first--;
            itr.first--;
            if(it.first) pq.push(it);
            if(itr.first) pq.push(itr);
        }

        while(pq.size()){
            pair<int,char> it = pq.top();
            pq.pop();
            answer +=it.second;
            // it.first--;
            // if(it.first) pq.push(it);
        }
        return answer;
    }
};