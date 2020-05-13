/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        for(int i = 0; i < k; ++i){
            if(num.size() <= 1) return "0";
            //cout << "num: " << num << ", k: " << i + 1 << endl;

            int mag;
            string prev = num;
            string next;
            string tmp;
            int comp;
            for(int j = 0; j < num.size(); ++j){  
                tmp = num;
                mag = 1;
                while(j == 0 && mag <= num.size() && tmp[mag] == '0') ++mag;
                next = tmp.erase(j, mag);
                
                if(mag > 1){
                    prev = next;
                    break;
                }
                
                if(prev.size() > next.size() || -prev.compare(next) <= 0){
                    prev = next;
                    //cout << "new prev: " << prev << endl;
                } else break;
            }
            
            num = prev;
        }
                      
        return num.size() == 0 ? "0" : num;
    }
};