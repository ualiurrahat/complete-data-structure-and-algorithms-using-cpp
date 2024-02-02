/*Your task is to maintain a data structure that supports the following functions of a web browser.
1- Browser(homepage): Set homepage of the browser

2- Visit(url): Visit the url from the current page. It clears up all the forward history.

3- Back(steps): Move ‘steps’ backward in the browser history

4- Forward(steps): Move ‘steps’ forward in the browser history
Note:
If you can’t move steps forward or backward, just return the last website that can be reached.
*/
#include <bits/stdc++.h>

using namespace std;
class Node
{

public:
    string data;
    Node *back;
    Node *next;
    // constructor
    Node() : data(0), back(nullptr), next(nullptr){};
    Node(string x) : data(x), back(nullptr), next(nullptr){};
    Node(string x, Node *back, Node *next) : data(x), back(back), next(next){};
};
class Browser
{
    Node *current;

public:
    Browser(string &homepage)
    {
        current = new Node(homepage);
    }

    void visit(string &url)
    {
        Node *newNode = new Node(url);
        current->next = newNode;
        newNode->back = current;
        current = current->next;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (current->back)
            {
                current = current->back;
                steps--;
            }
            else
            {
                break;
            }
        }
        return current->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (current->next)
            {
                current = current->next;
                steps--;
            }
            else
            {
                break;
            }
        }
        return current->data;
    }
};
