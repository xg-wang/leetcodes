#include "lc_header.h"
using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for(int i = 0 ; i < words.size() ; i++) {
            wordMap[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        int i = 0, j = 0, dist = INT_MAX;
        vector<int>& vec1 = wordMap[word1];
        vector<int>& vec2 = wordMap[word2];
        while(i < vec1.size() && j < vec2.size()) { 
            dist = min(dist, abs(vec1[i] - vec2[j]));
            vec1[i] < vec2[j] ? i++ : j++;
        }
        return dist;
    }
private:
    unordered_map<string, vector<int>> wordMap;

    // WordDistance(vector<string>& words) {
    //     g.clear();
    //     int len = words.size();
    //     for (int i = 0; i < len; i++) {
    //         if (!g.count(words[i])) {
    //             g[words[i]] = {};
    //         }
    //         for (int j = i+1; j < len; j++) {
    //             auto it = g[words[i]].find(words[j]); 
    //             if (it == g[words[i]].end()) {
    //                 g[words[i]][words[j]] = j - i;
    //             } else {
    //                 it->second = min(j - i, it->second);
    //             }
    //         }
    //     }
    // }

    // int shortest(string word1, string word2) {
    //     int d1 = (g[word1][word2] == 0 ? INT_MAX : g[word1][word2]);
    //     int d2 = (g[word2][word1] == 0 ? INT_MAX : g[word2][word1]); 
    //     return min(d1, d2);
    // }

// private:
//     unordered_map<string, unordered_map<string, int>> g;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");;