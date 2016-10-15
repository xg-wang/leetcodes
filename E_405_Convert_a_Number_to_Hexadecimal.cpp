#include "lc_header.h"
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        vector<char> dic = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string res;
        int mask = 15;
        for (int i = 0; i < 8 && num != 0; i++) {
    		res.push_back(dic[num & mask]);
    		num >>= 4;
    	}
        return string(res.rbegin(), res.rend());
    }
};