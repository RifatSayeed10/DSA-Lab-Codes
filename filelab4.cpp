#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file("rifat.txt");
    string text;
    char ch;
    int v = 0, c = 0, s = 0, d = 0;
    while (file.get(ch))
    {
        text += ch;

        if (isalpha(ch))
        {
            ch = tolower(ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                v++;
            }
            else
                c++;
        }
        else if (isdigit(ch))
            d++;
        else
            s++;
    }
    cout << text;
    file.close();

    cout << "Total characters read: " << text.length() << endl;
    cout << "Vowels: " << v << endl;
    cout << "Consonants: " << c << endl;
    cout << "Digits: " << d << endl;
    cout << "Special Characters: " << s << endl;
}