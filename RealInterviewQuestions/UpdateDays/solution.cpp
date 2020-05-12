#include "header.h"
#include <utility>

int main(){
    vector<pair<vector<int>, int> > cases;

    cases.push_back(pair<vector<int>, int>(vector<int>{}, -1));

    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,0,
                                                        0,0,0,0,
                                                        0,0,0,0,
                                                        0,0,0,0}, 0));

    cases.push_back(pair<vector<int>, int>(vector<int>{ 1,1,1,1,
                                                        1,1,1,1,
                                                        1,1,1,1,
                                                        1,1,1,1}, 0));
    
    cases.push_back(pair<vector<int>, int>(vector<int>{ 1,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,
                                                        0,0,0,1,1,1,0,0,
                                                        0,0,0,1,1,1,0,0,
                                                        0,0,0,0,0,0,0,0,
                                                        0,0,0,1,1,1,0,0,
                                                        0,0,0,0,0,0,1,1,
                                                        0,0,0,0,0,0,1,1}, 5));

    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,0,0,0,0,0,
                                                        0,1,0,0,0,0,1,0,
                                                        0,1,0,0,0,0,1,0,
                                                        0,1,0,0,0,0,1,0,
                                                        0,1,0,0,0,0,1,0,
                                                        0,1,1,0,0,1,1,0,
                                                        0,0,1,1,1,1,0,0,
                                                        0,0,0,0,0,0,0,0}, 3));
    
    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,0,0,0,0,0,
                                                        0,1,0,1,0,0,1,0,
                                                        0,1,1,1,0,0,1,0,
                                                        0,0,0,0,0,0,1,0,
                                                        0,1,0,0,0,0,1,0,
                                                        0,1,1,0,0,1,1,0,
                                                        0,0,1,1,1,1,0,0,
                                                        0,0,0,0,0,0,0,0}, 3));

    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,1,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0,
                                                        0,0,0,0,0,0,0,0,0}, 8));

    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,0,0,0,0,1,
                                                        0,0,0,0,0,0,0,1,
                                                        1,0,0,1,1,1,0,1,
                                                        1,0,1,1,0,1,0,1,
                                                        1,0,1,0,0,1,0,1,
                                                        1,0,1,0,0,1,0,1,
                                                        1,1,1,0,0,1,1,1,
                                                        0,0,0,0,0,0,0,0}, 3));
                                                        
    cases.push_back(pair<vector<int>, int>(vector<int>{ 0,0,0,1,1,0,1,1,1,1,
                                                        0,1,1,1,0,0,1,0,1,1,
                                                        0,1,1,1,1,0,1,0,1,1,
                                                        0,0,0,1,0,0,1,0,1,0,
                                                        0,0,0,1,0,0,1,0,0,1,
                                                        0,0,0,1,1,0,1,1,1,1,
                                                        1,0,0,1,1,1,1,0,1,1,
                                                        1,1,1,1,1,1,0,0,1,0,
                                                        1,0,0,0,1,1,1,0,1,1,
                                                        0,1,0,0,0,0,1,0,1,1}, 2));

    for(int i = 0; i < cases.size(); ++i){
        int result = solution(cases[i].first);

        cout << "Case " << i << " - ";
        if(result == cases[i].second)
            cout << "Passed: ";
        else
            cout << "Failed: ";
        cout << result << "/" << cases[i].second << endl;
    }
}