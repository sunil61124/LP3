#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Define the maximum number of unique characters (assuming ASCII set)
#define MAX_CHAR 256

// Node structure for the Huffman tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    // Constructor
    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparison function for priority queue to order nodes by frequency
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to traverse the Huffman Tree and store Huffman Codes in an array
void generateCodes(Node* root, string code, string huffmanCode[]) {
    if (root == nullptr)
        return;

    // If it's a leaf node (character node), assign the code
    if (!root->left && !root->right) {
        huffmanCode[(unsigned char)root->ch] = code;
    }

    // Traverse left with '0' and right with '1'
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Function to build the Huffman Tree and generate codes
void huffmanEncoding(const string& text) {
    // Frequency array to count occurrences of each character
    int freq[MAX_CHAR] = {0};
    for (char ch : text) {
        freq[(unsigned char)ch]++;
    }

    // Create a priority queue to store nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character with non-zero frequency
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            pq.push(new Node((char)i, freq[i]));
        }
    }

    // Iterate until we have one node left (the root of the Huffman Tree)
    while (pq.size() > 1) {
        // Remove the two nodes with the lowest frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        Node* sumNode = new Node('\0', left->freq + right->freq);
        sumNode->left = left;
        sumNode->right = right;

        // Add the new node to the priority queue
        pq.push(sumNode);
    }

    // Root of Huffman Tree
    Node* root = pq.top();

    // Array to store Huffman Codes
    string huffmanCode[MAX_CHAR];
    generateCodes(root, "", huffmanCode);

    // Display Huffman Codes
    cout << "Huffman Codes are:\n";
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            cout << (char)i << " : " << huffmanCode[i] << endl;
        }
    }

    // Encode the input text using Huffman codes
    cout << "\nEncoded text:\n";
    string encodedText = "";
    for (char ch : text) {
        encodedText += huffmanCode[(unsigned char)ch];
    }
    cout << encodedText << endl;
}

int main() {
    string text;
    cout << "Enter text to encode: ";
    cin >> text;

    huffmanEncoding(text);

    return 0;
}
