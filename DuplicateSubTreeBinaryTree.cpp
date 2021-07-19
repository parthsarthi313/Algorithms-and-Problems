// This is C++ code for finding Duplicate Sub Tree in a Binary Tree except leaf Nodes.
// Input format: 1st line number of test cases N.
//               next N line contains the value of nodes in Level Order Traversal.
//               Null nodes are represented as N.
//
//The solution to the problem is returned by dupSub() which in turn calls dubSubRecur.
//
//Time Complexity: O(n) as each node is visited once.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node *root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/


// This function takes a node and considers it as a root.
// The Inorder traversal of subtree rooted at this node is returned as string s.
// A map mp stores mapping of s to number of times s occured.
string dupSubRecur(Node *root, map<string, int> &mp){
    if(root == NULL)
        return "";

    //For inorder traversal left node, curr node and right nodes are accessed in the order.
    string left = dupSubRecur(root->left, mp);
    string node = to_string(root->data);
    string right = dupSubRecur(root->right, mp);

    string s = left + node + right;
    mp[s]++;
    return s;
}

class Solution {
  public:
    //This function returns 1 if the tree contains
    //a duplicate subtree of size 2 or more else returns false

    int dupSub(Node *root) {
         map<string, int> mp;
         bool flag = 0;

         dupSubRecur(root, mp);

         //if any of the subtrees except the leaf nodes have occurence greater than 1
         //then flag is set to 1;
         for(auto i : mp){
             if(i.first.size() > 1){
                 if(i.second > 1){
                     flag = 1;
                     break;
                 }
             }
         }

         return flag;
    }
};



int main()
{

	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}

//Thanks for reading this code :) ;
