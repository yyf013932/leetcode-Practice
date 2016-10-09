class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1||s.size()==0){
            return s;
        }
        string T=preProcess(s);
        int id=0,R=0,length=T.size();
        int p[length];
        for(int i=0;i<length;i++){
            int d=2*id-i;
            int diff=R-i;
            if(diff>0){
                if(p[d]<diff){
                    p[i]=p[d];
                }else{
                    p[i]=diff;
                    while((i+p[i]+1)<length&&(i-p[i]-1)>=0&&T[i+p[i]+1]==T[i-p[i]-1]){
                        p[i]++;
                    }
                    id=i;
                    R=id+p[i];
                }
            }else{
                p[i]=0;
                while((i+p[i]+1)<length&&(i-p[i]-1)>=0&&T[i+p[i]+1]==T[i-p[i]-1]){
                    p[i]++;
                }
                id=i;
                R=id+p[i];
            }
        }
        int maxLength=0,currentIndex=0;
        for(int i=0;i<length;i++){
            if(maxLength<p[i]){
                maxLength=p[i];
                currentIndex=i;
            }
        }
        string re="";
        int k=0;
        if(T[currentIndex]!='#')
            re+=T[currentIndex];
        while(k++<maxLength){
            if(T[currentIndex+k]=='#')
                continue;
            re=T[currentIndex+k]+re+T[currentIndex+k];
        }
        return re;
    }
    string preProcess(string s){
        string re="#";
        for(auto c:s){
            re=re+c+"#";
        }
        return re;
    }
};