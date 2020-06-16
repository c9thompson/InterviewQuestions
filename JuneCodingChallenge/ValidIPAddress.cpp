/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP == "") return "Neither";
        if(IP.back() == ':' || IP.back() == '.') return "Neither";
        
        bool v4flag = true;
        bool v6flag = true;
        
        int s = 0;
        int i = 0;
        int l = 0;
        int count = 0;
        while(i < IP.size() && (v4flag || v6flag)){
            if((count > 4 && !v6flag) || count > 7) return "Neither";
            
            while(i < IP.size() && (IP[i] != '.' && IP[i] != ':')){
                if(!isxdigit(IP[i]) && !isdigit(IP[i]))
                    return "Neither";
                    
                if(l > 4 || (l > 3 && !v6flag)) return "Neither";
                if(isalpha(IP[i])){
                    v4flag = false;
                    if(!v6flag) return "Neither";
                }
                
                i++;
                l = i - s;
            }
            
            if(l > 4 || l == 0) return "Neither";
            if(IP[i] == '.' || (v4flag && i == IP.size())){
                if(!v4flag) return "Neither";
                v6flag = false;
                
                if(l > 3 || (l > 1 && IP[s] == '0'))
                    return "Neither";
                if(stoi(IP.substr(s, l)) > 255) return "Neither";
            }
            
            if(IP[i] == ':'){
                if(!v6flag) return "Neither";
                v4flag = false;
            }
            
            count++;
            i++;
            s = i;
            l = 0;
        }
        
        if(v4flag && count == 4) return "IPv4";
        else if(v6flag && count == 8) return "IPv6";
        else return "Neither";
    }
};