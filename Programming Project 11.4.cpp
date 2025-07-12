#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class PermutationIterator {
public:
    PermutationIterator(string s) {
        original = s;
        current = s;
        isFirst = true;
        finished = false;
        sort(current.begin(), current.end());
    }

    string next_permutation() {
        if (isFirst) {
            isFirst = false;
            return current;
        }

        if (std::next_permutation(current.begin(), current.end())) {
            return current;
        }
        else {
            finished = true;
            return "";
        }
    }

    bool has_more_permutations() {
        return !finished;
    }

private:
    string original;
    string current;
    bool isFirst;
    bool finished;
};

int main() {
    PermutationIterator iter("chance");
    while (iter.has_more_permutations()) {
        cout << iter.next_permutation() << endl;
    }
    return 0;
}
