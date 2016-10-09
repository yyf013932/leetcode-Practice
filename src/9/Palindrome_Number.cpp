class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int tem=x;
        int re=0;
        while(tem>0){
            re=re*10+tem%10;
            tem/=10;
        }
        if(re==x){
            return true;
        }else{
            return false;
        }
    }
};