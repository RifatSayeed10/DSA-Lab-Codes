#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    int totalLoops = 0;
    int logLoops = 0;

    cout << "Enter your code (type END to finish):\n";

    while (getline(cin, line))
    {
        if (line == "END")
            break;

        string lower = line;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        lower.erase(remove(lower.begin(), lower.end(), ' '), lower.end());

        if (lower.find("for(") != string::npos || lower.find("while(") != string::npos)
        {
            totalLoops++;

            if (lower.find("*=2") != string::npos || lower.find("=x*2") != string::npos ||
                lower.find("=i*2") != string::npos || lower.find("=j*2") != string::npos ||
                lower.find("*2") != string::npos || lower.find("i=i*2") != string::npos)
                logLoops++;
        }
    }

    string complexity;
    if (totalLoops == 0)
        complexity = "O(1)";
    else if (totalLoops == 1 && logLoops == 0)
        complexity = "O(n)";
    else if (totalLoops == 1 && logLoops == 1)
        complexity = "O(log n)";
    else if (totalLoops >= 2 && logLoops >= 1)
        complexity = "O(n log n)";
    else if (totalLoops >= 2)
        complexity = "O(n^2)";
    else
        complexity = "O(n)";

    cout << "Best Case: ";
    if (complexity == "O(1)")
        cout << "O(1)\n";
    else if (complexity == "O(n)")
        cout << "O(1)\n";
    else if (complexity == "O(log n)")
        cout << "O(1)\n";
    else if (complexity == "O(n log n)")
        cout << "O(log n)\n";
    else if (complexity == "O(n^2)")
        cout << "O(n^2)\n";

    cout << "Average Case: " << complexity << "\n";
    cout << "Worst Case: " << complexity << "\n";

    return 0;
}
