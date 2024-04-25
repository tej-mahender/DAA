#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;
};
Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}
struct comp {
    bool operator()(Node* l, Node* r) {
        if (l->freq == r->freq)
            return l->ch > r->ch; // For equal frequencies, order by character
        return l->freq > r->freq;
    }
};
Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, comp>& Q) {
    int n = Q.size();
    for (int i = 1; i < n; i++) {
        Node* z = getNode('\0', 0, nullptr, nullptr);
        Node* x = Q.top(); Q.pop();
        Node* y = Q.top(); Q.pop();
        z->left = x;
        z->right = y;
        z->freq = x->freq + y->freq;
        Q.push(z);
    }
    return Q.top();
}
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
int main() {
    unordered_map<char, int> freq;
    char ch;
    int f, n;
    cout << "Enter the no. of characters: ";
    cin >> n;
    cout << "Enter characters and their frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> ch >> f;
        freq[ch] = f;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    Node* root = buildHuffmanTree(pq);
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    vector<pair<char, string>> sortedCodes(huffmanCode.begin(), huffmanCode.end());
    sort(sortedCodes.begin(), sortedCodes.end());
    cout << endl<<"Huffman Codes are : " << endl;
    for (auto pair: sortedCodes) {
        cout << pair.first << " - " << pair.second << endl;
    }
    return 0;
}
