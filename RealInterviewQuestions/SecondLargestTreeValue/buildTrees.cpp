#include "header.h"

tree::tree(int size) : root(NULL) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,10000);

    int addValue = distribution(generator);
    root = shared_ptr<node>(new node(addValue));

    min = addValue;
    second_min = INT_MAX;
    bool addSuccess = false;

    for(int i = 1; i < size; ++i){
        while(!addSuccess){
            addValue = distribution(generator);
            addSuccess = add(addValue, root);

            if(addSuccess){
                if(addValue < min){
                    second_min = addValue;
                    min = addValue;
                }else if(addValue < second_min) second_min = addValue;
            }
        }

        addSuccess = false;
    }
};

bool tree::add(int val, shared_ptr<node> n){
    if(val == n->value_) return false;

    if(val > n->value_){
        if(n->right_) return add(val, n->right_);
        else {
            n->right_ = shared_ptr<node>(new node(val));
            return true;
        }
    }else{
        if(n->left_) return add(val, n->left_);
        else {
            n->left_ = shared_ptr<node>(new node(val));
            return true;
        }
    }
};

