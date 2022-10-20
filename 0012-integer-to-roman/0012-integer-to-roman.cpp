class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<int> s;
        while(num!=0){
            int dig = num%10;
            s.push_back(dig);
            num = num/10;
        }
        reverse(s.begin(), s.end());
        // for(int i =0; i<s.size() ;i++){
        //     cout<<s[i];
        // }
        // cout<<endl;
        if(s[0]>=1 && s.size()==4){
            int times = s[0];
            while(times!=0){
                ans.push_back('M');
                times--;
            }
        }
        if((s.size()==4 && s[1]>=5 ) || (s.size()==3 && s[0]>=5)) {
            int temp = 0;
            if(s.size() == 3){
              temp = s[0];  
            }else{
                temp = s[1];
            }
            int times = temp-5;
            if(times!=4)
                ans.push_back('D');
            while(times<=3 && times!=0){
                ans.push_back('C');
                times--;
            }
            if(times == 4){
                ans = ans + "CM";
            }
        }
        else if((s.size()==4 && s[1]>=1) || (s.size()==3 && s[0]>=1)) {
            int temp = 0;
            if(s.size() == 3){
              temp = s[0];  
            }else{
                temp = s[1];
            }
            int times = temp;
            while(times<=3 && times!=0){
                ans.push_back('C');
                times--;
            }
            if(times == 4){
                ans = ans + "CD";
            }
        }
        if((s.size()==3 && s[1]>=5) || (s.size()==2 && s[0]>=5) || (s.size()==4 && s[2]>=5 )) {
            int temp = 0;
            if(s.size() == 2){
              temp = s[0];  
            }else if(s.size() == 3){
                temp = s[1];
            }else{
                temp = s[2];
            }
            int times = temp-5;
            if(times!=4)
            ans.push_back('L');
            while(times<=3 && times!=0){
                ans.push_back('X');
                times--;
            }
            if(times == 4){
                ans = ans + "XC";
            }
        }
        else if((s.size()==3 && s[1]>=1) || (s.size()==2 && s[0]>=1) || (s.size()==4 && s[2]>=1 )) {
            int temp = 0;
            if(s.size() == 2){
              temp = s[0];  
            }else if(s.size() == 3){
                temp = s[1];
            }else{
                temp = s[2];
            }
            int times = temp;
            
            while(times<=3 && times!=0){
                ans.push_back('X');
                times--;
            }
            if(times == 4){
                ans = ans + "XL";
            }
        }
        if((s.size()==2 && s[1]>=5 ) || (s.size()==1 && s[0]>=5) || (s.size()==3 && s[2]>=5 ) || (s.size()==4 && s[3]>=5 )) {
            int temp = 0;
            if(s.size() == 1){
              temp = s[0];  
            }else if(s.size() == 2){
                temp = s[1];
            }else if(s.size() == 3){
                temp = s[2];
            }else{
                temp = s[3];
            }
            int times = temp-5;
            if(times!=4)
            ans.push_back('V');
            while(times<=3 && times!=0){
                ans.push_back('I');
                times--;
            }
            if(times == 4){
                ans = ans + "IX";
            }
        }
        else if((s.size()==2 && s[1]>=1 ) || (s.size()==1 && s[0]>=1 ) || (s.size()==3 && s[2]>=1 ) || (s.size()==4 && s[3]>=1 )) {
            int temp = 0;
            if(s.size() == 1){
              temp = s[0];  
            }else if(s.size() == 2){
                temp = s[1];
            }else if(s.size() == 3){
                temp = s[2];
            }else{
                temp = s[3];
            }
            int times = temp;
            while(times<=3 && times!=0){
                ans.push_back('I');
                times--;
            }
            if(times == 4){
                ans = ans + "IV";
            }
        }
        return ans;
    }
};