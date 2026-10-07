//Name -> Rajni
//Roll No. -> 25/A07/052


#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node{
    char ch;
    int freq;

    Node *left;
    Node *right;

    Node(char c, int f){
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

void generateCodes(Node *root, string code, map<char, string> &huffmanCode){
    if (root == NULL)
        return;
        
    if (root->left == NULL && root->right == NULL){
        huffmanCode[root->ch] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main(){
    string text;

    cout << "Enter the string: ";
    cin >> text;

    map<char, int> frequency;

    for (char ch : text){
        frequency[ch]++;
    }
    
    priority_queue<Node *, vector<Node *>, Compare> pq;
    
    for (auto x : frequency){
        pq.push(new Node(x.first, x.second));
    }

    while (pq.size() > 1){
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node *root = pq.top();
    
    map<char, string> huffmanCode;

    generateCodes(root, "", huffmanCode);
    
    cout << "\nHuffman Codes:\n";

    for (auto x : huffmanCode){
        cout << x.first << " : " << x.second << endl;
    }

    // Encode the string
    string encodedString = "";

    for (char ch : text){
        encodedString += huffmanCode[ch];
    }

    cout << "\nOriginal String: " << text;
    cout << "\nEncoded String: " << encodedString << endl;

    return 0;
}
