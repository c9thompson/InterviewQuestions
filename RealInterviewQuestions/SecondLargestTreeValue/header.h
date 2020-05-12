#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <random>
#include <queue>
#include <utility>

using namespace std;

class node{
    public:
        shared_ptr<node> left_;
        shared_ptr<node> right_;
        int value_;

        node() : left_(NULL), right_(NULL), value_(-1) {};
        node(int val) : left_(NULL), right_(NULL), value_(val) {};
        node(node left, node right, int val) : left_(&left), right_(&right), value_(val) {};
};

class tree{
    private:
        int min;
        int second_min;
        shared_ptr<node> root;

        bool add(int val, shared_ptr<node> n);

    public:
        tree(int size);

        int getMin() {return min;};
        int getSecondMin() {return second_min;};
        shared_ptr<node> getRoot() {return root;};
};

int solution(shared_ptr<node> n);
