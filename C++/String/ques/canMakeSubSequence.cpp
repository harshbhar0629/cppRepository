 bool canMakeSubsequence(string str1, string str2) {
        
        int len1= str1.size();
        int len2 = str2.size();
        int count =0;
        int idx2=0;
        
        for(int i=0;i<len2;i++){
           
            char ch = str2[i];
            char orig = ch;
            if(ch == 'a'){
                ch='z';
            }
            else {
                ch--;
            }
            
            while(idx2<len1){
             
                char c = str1[idx2];
                if(c==ch || c==orig){
                    count++;
                    idx2++;
                    break;
                }
                else idx2++;
            }
        }
        
        if(count==len2) return true;
        else return false;
        
    }
