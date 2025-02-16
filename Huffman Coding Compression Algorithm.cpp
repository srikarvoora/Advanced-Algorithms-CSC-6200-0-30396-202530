#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char data;      
    int freq;      
    Node* left;    
    Node* right;   

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; 
    }
};

void assignCodes(Node* node, string code, map<char, string>& huffmanCodes) {
    if (node == NULL) {
        return;
    }

    if (node->data != '$') {
        huffmanCodes[node->data] = code;
    }

    assignCodes(node->left, code + "0", huffmanCodes);
    assignCodes(node->right, code + "1", huffmanCodes);
}

void buildHuffmanTree(string S, int f[], int N) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < N; i++) {
        Node* node = new Node(S[i], f[i]);
        pq.push(node);
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); 
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent); 
    }

    Node* root = pq.top(); 
    string code = "";
    map<char, string> huffmanCodes;

    assignCodes(root, code, huffmanCodes); 

    cout << "Huffman Codes:" << endl;
    for (map<char, string>::iterator it = huffmanCodes.begin(); it != huffmanCodes.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}

int main() {
    string S = "abcdef"; 
    int f[] = {5, 9, 12, 13, 16, 45}; 
    int N = sizeof(f) / sizeof(f[0]); 

    buildHuffmanTree(S, f, N); 

    return 0;
}

