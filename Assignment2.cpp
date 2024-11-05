
#include <bits/stdc++.h>
using namespace std;

struct node
{
    char c;
    int data;
    node *left;
    node *right;

    node(char ch, int d)
    {
        c = ch;
        data = d;
        left = NULL;
        right = NULL;
    }
};

struct compare
{
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

class Huffman
{
    int n;
    vector<pair<char, int>> input;
    node *root;

    public:
        void accept();
        void display();
        void huffman_operation();
        void code_generation(node *, string, unordered_map<char, string> &);
};

void Huffman::accept()
{
    cout << "\nEnter the size of array : ";
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i].first;
        cin >> input[i].second;
    }

    sort(input.begin(), input.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         { return a.second < b.second; });
    display();
    huffman_operation();
}

void Huffman::huffman_operation()
{
    priority_queue<node *, vector<node *>, compare> min_heap;

    for (int i = 0; i < n; i++)
    {
        node *newNode = new node(input[i].first, input[i].second);
        min_heap.push(newNode);
    }

    while (min_heap.size() > 1)
    {
        node *left_node = min_heap.top();
        min_heap.pop();
        node *right_node = min_heap.top();
        min_heap.pop();

        int result = left_node->data + right_node->data;
        node *curr = new node('\0', result);
        curr->left = left_node;
        curr->right = right_node;
        min_heap.push(curr);
    }

    root = min_heap.top();
    unordered_map<char, string> huffman_code;
    code_generation(root, "", huffman_code);

    for (const auto &item : input)
    {
        cout << item.first << "\t" << huffman_code[item.first] << endl;
    }
}

void Huffman::code_generation(node *curr, string code, unordered_map<char, string> &huffman_code)
{
    if (!curr)
    {
        return;
    }

    if (curr->left == NULL && curr->right == NULL)
    {
        huffman_code[curr->c] = code;
    }

    code_generation(curr->left, code + "0", huffman_code);
    code_generation(curr->right, code + "1", huffman_code);
}

void Huffman::display()
{
    cout << "\nCharacter\tFrequency" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "  " << input[i].first << "\t\t  " << input[i].second << endl;
    }
}

int main()
{
    Huffman obj;
    obj.accept();
}