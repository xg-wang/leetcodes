/*
Suppose we abstract our file system by a string in the following manner:

The string `"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"` represents:

    dir
        subdir1
        subdir2
            file.ext

The directory `dir` contains an empty sub-directory `subdir1` and a sub-directory `subdir2` containing a file `file.ext`.

The string `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"` represents:

    dir
        subdir1
            file1.ext
            subsubdir1
        subdir2
            subsubdir2
                file2.ext

The directory `dir` contains two sub-directories `subdir1` and `subdir2`. `subdir1` contains a file `file1.ext` and an empty second-level sub-directory `subsubdir1`. `subdir2` contains a second-level sub-directory `subsubdir2` containing a file `file2.ext`.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is `"dir/subdir2/subsubdir2/file2.ext"`, and its length is `32` (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return `0`.

Note:

* The name of a file contains at least a `.` and an extension.
* The name of a directory or sub-directory will not contain a `.`.

Time complexity required: `O(n)` where `n` is the size of the input string.

Notice that `a/aa/aaa/file1.txt` is not the longest file path, if there is another path `aaaaaaaaaaaaaaaaaaaaa/sth.png`.
 */

#include <sstream>
#include "lc_header.h"

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int longest_len = 0;
        stringstream ss(input);
        string item;
        char delim = '\n';
        vector<string> elems;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }

        vector<int> base_lengths = {0};
        for (string ele: elems) {
            string::iterator beg = ele.begin();
            int nindent = count_tab(beg);
            if (is_file(beg, ele.end())) {
                longest_len = max(longest_len, base_lengths[nindent] + (int)(ele.end() - beg));
            } else {
                if (nindent == base_lengths.size() - 1) {
                    // this is a subdir
                    base_lengths.push_back((int)(ele.end() - beg) + base_lengths.back() + 1);
                } else {
                    base_lengths.resize((size_t)(nindent + 2));
                    base_lengths[nindent + 1] = (int)(ele.end() - beg) + base_lengths[nindent] + 1;
                }
            }
        }

        return longest_len;
    }

private:
    bool is_file(const string::iterator beg, const string::iterator end) {
        string::iterator it = end - 1;
        if (*it == '.' || it == beg) return false;
        while (--it != beg) {
            if (*it == '.') return true;
        }
        return false;
    }

    int count_tab(string::iterator &it) {
        int ntab = 0;
        while (*it == '\t') {
            ntab++;
            it++;
        }
        return ntab;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    // 32
    cout << "32 == " << sol.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    // 0
    cout << "0 == " << sol.lengthLongestPath("a") << endl;
    // 8
    cout << "8 == " << sol.lengthLongestPath("file.ext") << endl;
    // 13
    cout << "13 == " << sol.lengthLongestPath("dir/fi.le.ext") << endl;
    return 0;
}