class Solution {
public:
    int divide(int dividend, int divisor) {
        int cnt;
        long long ans=0;
        bool sign=true;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>=0 && divisor<0) sign=false;
        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);
        while(n>=d){
            cnt=0;  
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(long long)1<<cnt;
            n-=d*((long long)1<<cnt);
        }
        if(ans==1<<31 && sign) return INT_MAX;
        if(ans==1<<31 && !sign) return INT_MIN;
        if(sign==false) return -ans;
        return ans;
    }
};