#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node *prev;
    Node(string data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = NULL;
    }
    void InsertAtEnd(string data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Function to return precedence of operators
int precedence(string ch)
{
    if (ch == "multiply" || ch == "divide")
    {
        return 2;
    }
    if (ch == "add" || ch == "subtract")
    {
        return 1;
    }
    return -1;
}

// Function to calculate based on operator and operands
int calc(int n1, int n2, string op)
{
    if (op == "add")
    {
        return (n1 + n2);
    }
    if (op == "subtract")
    {
        return (n1 - n2);
    }
    if (op == "multiply")
    {
        return (n1 * n2);
    }
    if (op == "divide")
    {
        return (n1 / n2);
    }
    return -1;
}

// Function to check if the string is a number
bool isNumber(string c)
{
    for (char ch : c)
    {
        if (ch < '0' || ch > '9')
        {
            return false;
        }
    }
    return true;
}

// Function to compute the result from a linked list representing the expression
int Result(LinkedList &obj)
{
    Node *curr = obj.head;
    stack<int> operands;
    stack<string> operators;

    while (curr != NULL)
    {
        if (isNumber(curr->data))
        {
            operands.push(stoi(curr->data)); // Use stoi for integer conversion
        }
        else if (curr->data == "(")
        {
            operators.push(curr->data);
        }
        else if (curr->data == ")")
        {
            while (!operators.empty() && operators.top() != "(")
            {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                string oper = operators.top();
                operators.pop();
                int result = calc(left, right, oper);
                operands.push(result);
            }
            if (!operators.empty())
            {
                operators.pop(); // Pop the opening parenthesis
            }
        }
        else
        {
            // Operator precedence check
            while (!operators.empty() && precedence(operators.top()) >= precedence(curr->data))
            {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                string oper = operators.top();
                operators.pop();
                int result = calc(left, right, oper);
                operands.push(result);
            }
            operators.push(curr->data);
        }
        curr = curr->next;
    }

    // Final calculation for remaining operators in the stack
    while (!operators.empty())
    {
        int right = operands.top();
        operands.pop();
        int left = operands.top();
        operands.pop();
        string oper = operators.top();
        operators.pop();
        int result = calc(left, right, oper);
        operands.push(result);
    }

    return operands.top();
}

int main()
{
    LinkedList ll;
    ll.InsertAtEnd("10");
    ll.InsertAtEnd("add");
    ll.InsertAtEnd("(");
    ll.InsertAtEnd("12");
    ll.InsertAtEnd("multiply");
    ll.InsertAtEnd("(");
    ll.InsertAtEnd("2");
    ll.InsertAtEnd(")");
    ll.InsertAtEnd("subtract"); // Fixed to match 'subtract'
    ll.InsertAtEnd("2");
    ll.InsertAtEnd(")");

    ll.display();                             // Output: 10 add ( 12 multiply ( 2 ) subtract 2 )
    cout << "Result: " << Result(ll) << endl; // Should print the final result
}