#include "lc_header.h"
using namespace std;

/*
 * Complete the function below.
 */
long countX(vector < string > steps) {
    long res;
    long min_first = LONG_MAX, min_second = LONG_MAX;
    for (int i = 0; i < steps.size(); i++) {
        cout << steps[i] << endl;
        auto pos = steps[i].find(' ');
        string fele_str = steps[i].substr(0, pos);
        string sele_str = steps[i].substr(pos+1);
        cout << fele_str << ", " << sele_str << endl;
        min_first = min(min_first, stol(fele_str));
        min_second = min(min_second, stol(sele_str));
    }
    return min_first * min_second;
}



