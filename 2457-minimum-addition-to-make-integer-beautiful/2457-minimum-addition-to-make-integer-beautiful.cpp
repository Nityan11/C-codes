class Solution {
public:
    int countdig(long long n){
        int sum = 0;
        while(n!=0){
            int dig = n%10;
            sum += dig;
            n = n/10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long num = 10;
        if(countdig(n)<=target){
            return 0;
        }
        for(int i = 1; i<13; i++){
            long long n2 = (n/num + 1)*num;
            if(countdig(n2)<=target){
                return n2-n;
            }
            num = num*10;
        }
        return 0;
    }
};