#include <iostream>
#include <stack>
#include <cctype> // for isdigit

using namespace std;

int evaluatePostfix(string expr)
{
    stack<int> s;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (isdigit(ch))
        {
            s.push(ch - '0'); // convert char to int
        }
        else if (ch == ' ')
        {
            continue; // skip spaces
        }
        else
        {
            // Pop two operands
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            default:
                cout << "Invalid operator: " << ch << endl;
                return 0;
            }
        }
    }

    return s.top();
}

int main()
{
    string expr;
    cout << "Enter postfix expression (e.g., 231*+9-): ";
    cin >> expr;

    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;

    return 0;
}
