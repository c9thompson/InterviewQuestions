#include "header.h"

int main(){
    int number_of_tests = 10;

    for(int i = 0; i < number_of_tests; ++i){
        tree test(10);
        int result = solution(test.getRoot());

        cout << "Case " << i << " - ";
        if(result == test.getSecondMin())
            cout << "Passed: ";
        else
            cout << "Failed: ";
        cout << result << "/" << test.getSecondMin() << endl;
    }
}