struct Node {
    int data;
    Node *next;
    Node(int d, Node *n):data(d),next(n){}
};

class Queue {
    Node *node = NULL;
    int len = 0;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if (len==0) {
            node = new Node(x, NULL);
            len++;
            return;
        }
        int tmp = len;
        Node *iter = node;
        while (tmp-->1) {
            iter = iter->next;
        }
        iter->next = new Node(x, NULL);
        len++;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        Node *tmp = node->next;
        delete node;
        len--;
        node = tmp;
    }

    // Get the front element.
    int peek(void) {
        return node->data;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return len==0;
    }
};