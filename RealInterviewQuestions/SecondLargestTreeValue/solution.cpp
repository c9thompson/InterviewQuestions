#include "header.h"
#include "math.h"

int findTreeMax(shared_ptr<node> n){
    return n->right_ ? findTreeMax(n->right_) : n->value_;
}

int second_largest(shared_ptr<node> n, bool& bottomFlag){
    if(n->right_){
        int value = second_largest(n->right_, bottomFlag);
        if(bottomFlag){
            bottomFlag = false;
            return n->value_;
        } else {
            return value;
        }
    }else if(n->left_){
        return findTreeMax(n->left_);
    }else{
        bottomFlag = true;
        return n->value_;
    }
}

int solution(shared_ptr<node> n){
    if(!n->left_ && !n->right_) return INT_MIN;

    bool bottomFlag = false;
    return second_largest(n, bottomFlag);
}