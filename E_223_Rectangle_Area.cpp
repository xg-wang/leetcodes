#include "lc_header.h"

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ina = max(A, E);
        int inb = max(B, F);
        int inc = min(C, G);
        int ind = min(D, H);
        return get_area(A,B,C,D) +
               get_area(E,F,G,H) -
               get_area(ina,inb,inc,ind);
    }
private:
    int get_area(int a, int b, int c, int d) {
        if (c < a || d < b) {
            return 0;
        } else {
            return (c - a) * (d - b);
        }
    }
};
