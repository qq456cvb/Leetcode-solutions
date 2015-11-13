struct Node {
    int data;
    Node *next;
    Node(int d, Node *n):data(d),next(n){}
};

class Stack {
    Node *node;
    int len = 0;
public:
    // Push element x onto stack.
    void push(int x) {
        if (len==0) {
            node = new Node(x, NULL);
            len++;
            return;
        }
        Node *front = new Node(x, node);
        len++;
        node = front;
    }

    // Removes the element on top of the stack.
    void pop() {
        Node *tmp = node->next;
        delete node;
        len--;
        node = tmp;
    }

    // Get the top element.
    int top() {
        int result = node->data;
        return result;
    }

    // Return whether the stack is empty.
    bool empty() {
        return len == 0;
    }
};