#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// New version without regex
int getLoopComplexitySimple(string line) {
    // Remove all spaces to make condition checks easier
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    // Check for "for(" or "while("
    if (line.find("for(") != string::npos || line.find("while(") != string::npos) {
        // Check for <n or <=n
        if (line.find("<n") != string::npos || line.find("<=n") != string::npos)
            return 1; // O(n)

        // Check for log(n)
        if (line.find("log(n)") != string::npos || line.find("logn") != string::npos)
            return 2; // O(log n)
    }

    return 0; // Not a loop or can't analyze
}

string getComplexityString(int totalLoops) {
    if (totalLoops == 0) return "O(1)";
    else if (totalLoops == 1) return "O(n)";
    else return "O(n^" + to_string(totalLoops) + ")";
}

int main() {
    cout << "Enter your code (end with a line containing only END):\n";

    vector<string> code;
    string line;
    while (getline(cin, line)) {
        if (line == "END") break;
        code.push_back(line);
    }

    stack<int> loopStack;
    int maxDepth = 0, currentDepth = 0;

    for (const string& line : code) {
        if (line.find("for") != string::npos || line.find("while") != string::npos) {
            int loopType = getLoopComplexitySimple(line);
            if (loopType == 1 || loopType == 2) {
                loopStack.push(loopType);
                currentDepth++;
                if (currentDepth > maxDepth)
                    maxDepth = currentDepth;
            }
        }

        if (line.find("}") != string::npos && !loopStack.empty()) {
            loopStack.pop();
            currentDepth--;
        }
    }

    cout << "\nEstimated Time Complexity (Worst Case): " << getComplexityString(maxDepth) << endl;
    cout << "Estimated Time Complexity (Best Case): Depends on condition - assume O(1) to " << getComplexityString(maxDepth) << endl;
    cout << "Estimated Time Complexity (Average Case): Around " << getComplexityString(maxDepth) << endl;

    return 0;
}
