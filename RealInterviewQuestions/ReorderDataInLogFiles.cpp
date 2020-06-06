/*
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 

Constraints:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.
*/

class Solution {
public:
    static bool stringSort(string a, string b){
        return a < b;
    }
    
    static bool customStringSort(pair<string, string> a, pair<string, string> b){
        if(a.second == b.second){
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter;
        vector<char> digit;
        
        for(int i = 0; i < logs.size(); ++i){
            int nextSpace = logs[i].find(" ");
            
            if(logs[i][nextSpace + 1] > 57 /*ascii char value for 9*/){
                string id = logs[i].substr(0, nextSpace);
                string end = logs[i].substr(nextSpace, logs[i].size());
                    
                /*// ---- if log[i] elements also needed to be sorted ---
                vector<string> tmp;
                int prevPose = nextSpace + 1;
                nextSpace = end.find(" ", prevPose);
                
                while(nextSpace != std::string::npos){
                    tmp.push_back(end.substr(prevPose, nextSpace - prevPose));
                    
                    prevPose = nextSpace + 1;
                    nextSpace = end.find(" ", prevPose);
                }
                tmp.push_back(end.substr(prevPose, logs[i].size() - prevPose));
                
                sort(tmp.begin(), tmp.end(), stringSort);
                end = "";
                for(int j = 0; j < tmp.size() - 1; ++j)
                    end += tmp[j] + " ";
                end += tmp.back();     
                */
                
                letter.push_back(pair<string, string>(id, end));
            }else{
                digit.push_back(i);
            }
        }
        
        sort(letter.begin(), letter.end(), customStringSort);
        
        vector<string> output(logs.size());
        for(int i = 0; i < logs.size(); ++i){
            if(i >= letter.size())
                output[i] = logs[digit[i - letter.size()]];
            else
                output[i] = letter[i].first + letter[i].second;
        }
        
        return output;
    }
};