#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
    const int N = 100;
    int arr[N];
    int count = 0;
    int num;
    ifstream file("rifat.txt");
    while (file >> num && count < N)
    {
        arr[count++] = num;
    }
    file.close();
    sort(arr, arr + count);
    ofstream outFile("sorted.txt");
    for (int i = 0; i < count; ++i)
    {
        outFile << arr[i] << " ";
    }
    outFile.close();
    cout << "sorting completed";
    return 0;
}