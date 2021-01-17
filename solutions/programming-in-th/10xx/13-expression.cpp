#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

bool isOperator(char c)
{
    char operators[] = { '+', '-', '*', '/', '^' };
    for (int i = 0; i < 5; i++)
    {
        if (operators[i] == c)
            return true;
    }
    return false;
}

class Expression
{
    public:

    // should normally be a char but associativity sucks (e.g. a+b+c has two pluses)
    vector<char> operators;
    vector<Expression> operands;

    Expression()
    {

    }

    Expression(char c)
    {
        operators.push_back(c);
    }

    Expression(char c, Expression l)
    {
        operators.push_back(c);
        operands.push_back(l);
    }

    Expression(char c, Expression l, Expression r)
    {
        operators.push_back(c);
        operands.push_back(l);
        operands.push_back(r);
    }

    void toSS(stringstream &output)
    {
        if (operators[0] == '(')
        {
            output << "(";
            if (!operands.empty())
                operands[0].toSS(output);
            output << ")";
        }
        else if (isOperator(operators[0]))
        {
            operands[0].toSS(output);
            for (int i = 0, n = operators.size(); i < n; i++)
            {
                output << operators[i];
                operands[i + 1].toSS(output);
            }
        }
        else
        {
            output << operators[0];
        }
    }

    string toString()
    {
        stringstream output;
        toSS(output);
        return output.str();
    }
};

bool isHigher(char a, char b)
{
    if (a == '^') // ^ is always higher than everything
        return true;
    
    // others, same priority is considered higher for sake of left-right precendence
    if (a == '*' || a == '/')
        return b != '^';
    
    if (a == '+' || a == '-')
        return b == '+' || b == '-';
    
    return false;
}

bool isSame(char a, char b)
{
    if (a == '^')
        return b == '^';
    if (a == '*' || a == '/')
        return b == '*' || b == '/';
    if (a == '+' || a == '-')
        return b == '+' || b == '-';
    return false;
}

// pulls two results and join them with top operator
void handle(stack<char> &operators, stack<Expression> &results)
{
    char oper = operators.top();
    operators.pop();

    Expression right = results.top();
    results.pop();
    Expression left = results.top();
    results.pop();

    Expression add;
    if (isSame(left.operators.front(), oper))
    {
        vector<char> operators(left.operators);
        operators.push_back(oper);

        vector<Expression> operands(left.operands);
        operands.push_back(right);

        add.operators = operators;
        add.operands = operands;
    }
    else
    {
        add.operators.push_back(oper);
        add.operands.push_back(left);
        add.operands.push_back(right);
    }
    
    results.push(add);
}

Expression infixToTree(string infix)
{
    stack<char> operators;
    stack<Expression> results;

    // using same algorithm as infix to RPN
    for (string::iterator it = infix.begin(); it != infix.end(); ++it)
    {
        char c = *it;

        // case 1: + - * / ^
        if (isOperator(c))
        {
            // ) signifies opening bracket with no expression inside
            // turn it to ( as we now have some here
            if (!operators.empty() && operators.top() == ')')
                operators.top() = '(';
            
            // pop and create expression as long as top has higher prec. than current and not brackets
            while (!operators.empty() && operators.top() != '(' && isHigher(operators.top(), c))
                handle(operators, results);

            // push current operator to waiting list
            operators.push(c);
        }

        // case 2: (
        else if (c == '(')
        {
            if (!operators.empty() && operators.top() == ')')
                operators.top() = '(';
            operators.push(')');
        }

        // case 3: )
        else if (c == ')')
        {
            // case of null brackets
            if (operators.top() == ')')
            {
                Expression add('(');
                results.push(add);
            }

            // else just wrap previous expression in a bracket
            else
            {
                while (!operators.empty() && operators.top() != '(')
                    handle(operators, results);
                
                Expression add('(', results.top());
                results.pop();
                results.push(add);
            }

            operators.pop();
        }

        // case 4: operands
        else
        {
            Expression add(c);
            results.push(add);
        }
    }

    // wipe
    while (!operators.empty())
        handle(operators, results);

    return results.top();
}

void genTraversed(vector<int>::iterator begin, vector<int>::iterator end, stringstream &output)
{
    // base case
    if (begin == end - 1)
    {
        cout << "op(" << *begin << ",p)";
        return;
    }

    cout << "op(" << *(end - 1) << ",";
    genTraversed(begin, end - 1, output); 
    cout << ")";
}

string genTraversedString(vector<int> traversed)
{
    if (traversed.empty())
        return "p";
        
    stringstream output;
    genTraversed(traversed.begin(), traversed.end(), output);
    return output.str();
}

int main()
{
    // read expression
    string exp;
    cin >> exp;
    Expression result = infixToTree(exp);

    // read each sub-part input
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // keep track of traversed list
        vector<int> traversed;
        Expression *current = &result;

        // accept traversing
        while (true)
        {
            int move;
            cin >> move;
            if (move == 0)
                break;
                
            traversed.push_back(move);

            // if traversed to null, set current to null
            if (current == NULL || (isalpha((*current).operators[0]) && move == 1))
                continue;
            else if ((*current).operands.size() < move)
                current = NULL;
            else
                current = &((*current).operands[move - 1]);
        }

        // output in form of op(...)=p
        cout << genTraversedString(traversed) << "=";
        if (current == NULL)
            cout << "null";
        else
            cout << (*current).toString();
        cout << endl;
    }

    return 0;
}