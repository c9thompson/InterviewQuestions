#include "header.h"
#include <utility>

int main(){
    vector<pair<pair<string,string>, int>> cases;

    cases.push_back(pair<pair<string, string>, int>(pair<string, string>("10.30.1", "10.31.1"), -1));

    for(int i = 0; i < cases.size(); ++i){
        int result = solution(cases[i].first.first, cases[i].first.second);

        cout << "Case " << i << " - ";
        if(result == cases[i].second)
            cout << "Passed: ";
        else
            cout << "Failed: ";
        cout << result << "/" << cases[i].second << endl;
    }
}