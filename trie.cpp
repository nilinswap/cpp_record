#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	   char val;
       Node *arr[26] = {NULL};
	   bool ends_here = false;
	Node(char c){
		val = c;
		ends_here = false;
	}
};

void insert(Node *root, string st, int pos){

	//base case
	if(pos == st.size()){
		root->ends_here = true;
		return;
	}


	//complex case
	if(!(root->arr[st[pos] - 'a'])){
		root->arr[st[pos]- 'a'] = new Node(st[pos]);
	}
	return insert(root->arr[st[pos]-'a'], st, pos+1);
}


bool search(Node *root, string st, int pos){

	//base case
	if(pos == st.size()){
		return root->ends_here;
	}


	//complex case
	return root->arr[st[pos]-'a'] && search(root->arr[st[pos]-'a'], st, pos+1);
}

int main(){

	string s = "hello";
	Node *root = new Node('0');

	insert(root, s, 0);
cout << search(root, s, 0) << endl;
	s = "hell";
	insert(root, s, 0);
cout <<search(root, s, 0) <<endl;;

	s = "help";
	insert(root, s, 0);

	cout <<search(root, s, 0) <<endl;;
	cout <<search(root, "hel", 0) <<endl;;
	cout <<search(root, "dep", 0) <<endl;
	return 0;
}
