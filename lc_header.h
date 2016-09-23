#ifndef _LC_HEADER_H_
#define _LC_HEADER_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <cassert>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template<typename T>
void print_array(std::vector<T> vec, std::string prefix="") {
    std::cout << prefix;
    for (size_t i = 0; i < vec.size()-1; i++) {
        std::cout << vec[i] << ", "; 
    }
    std::cout << vec.back() << std::endl;
}

#endif
