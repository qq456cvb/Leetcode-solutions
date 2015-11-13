class Node {
public:
    Node *a;
    Node *c;
    Node *g;
    Node *t;
    int cnt;
    Node() {
        cnt = 0;
        a = c = g = t = NULL;
        
    }
};

// this solution is dirty, there is no need to construct a tree, use brute force string match instead.
class Solution {
    Node *root;
    vector<string> results;
public:
    bool findNode(string s, Node *node) {
        if (s == "") {
            if (node->cnt == 1) {
                return true;
            } else {
                return false;
            }
        }
        char c = s[0];
        switch (c) {
            case 'A': {
                if (!node->a) {
                    return false;
                }
                return findNode(s.substr(1, 10), node->a);
            }
            case 'C': {
                if (!node->c) {
                    return false;
                }
                return findNode(s.substr(1, 10), node->c);
            }
            case 'G': {
                if (!node->g) {
                    return false;
                }
                return findNode(s.substr(1, 10), node->g);
            }
            case 'T': {
                if (!node->t) {
                    return false;
                }
                return findNode(s.substr(1, 10), node->t);
            }
        }
        return false;
    }
    
    void buildNode(string s, Node *node) {
        if (s == "") {
            node->cnt++;
            return;
        }
        char c = s[0];
        switch (c) {
            case 'A': {
                if (!node->a) {
                    node->a = new Node();
                }
                buildNode(s.substr(1, 10), node->a);
                break;
            }
            case 'C': {
                if (!node->c) {
                    node->c = new Node();
                }
                buildNode(s.substr(1, 10), node->c);
                break;
            }
            case 'G': {
                if (!node->g) {
                    node->g = new Node();
                }
                buildNode(s.substr(1, 10), node->g);
                break;
            }
            case 'T': {
                if (!node->t) {
                    node->t = new Node();
                }
                buildNode(s.substr(1, 10), node->t);
                break;
            }
        }
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        root = new Node();
        int i = 0;
        while (i < (int)s.length() - 9)  {
            string str = s.substr(i, 10);
            if (findNode(str, root)) {
                results.push_back(str);
            }
            buildNode(str, root);
            i++;
        }
        return results;
    }
};
