/*

Leetcode Problem Link:

https://leetcode.com/problems/minimize-xor/

*/

class Solution {
public:
    string binary(int n) {
        string b = "";
        while(n > 0) {
            b += to_string(n%2);
            n/=2;
        }
        reverse(b.begin(), b.end());
        return b;
    }
    
     int decimal(string b) {
        int n = 0;
        for(int i = b.length()-1; i >= 0; i--) {
            if(b[i] == '1') {
                n += pow(2, b.length()-i-1);
            }     
        }
        return n;
    }
    
    int minimizeXor(int num1, int num2) {
        int x = __builtin_popcount(num2);
        string s = binary(num1);
        string ans = "";
        if(x >= s.length()) {
            while(x--) {
                ans+="1";
            }
        } else {
            for(int i = 0 ; i < s.length(); i++) {
                if(s[i] == '1' && x > 0) {
                    ans+="1";
                    x--;
                } else {
                    ans+="0";
                }
            }
            for(int i = s.length() - 1 ; x > 0 && i >= 0; i--) {
                if(s[i] == '0') {
                    ans[i] = '1';
                    x--;
                }
            }   
            
            
        }
        return decimal(ans);
    }
};
