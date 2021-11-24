#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int value;
	Node *left, *right;
	Node(int v, Node *l=NULL, Node *r=NULL)
		:value{v}, left{l}, right{r} {}
};

Node* createBalancedBST(vector<int> nums, int s=0, int e=-1){
	if(e<0) e=nums.size()-1;
	if(e==s) return new Node(nums[s]);
	if(e-s==1)
		return new Node(nums[e], createBalancedBST(nums, s, e-1));
	int mid = (s+e)/2;
	return new Node(nums[mid], 
		createBalancedBST(nums, s, mid-1),
		createBalancedBST(nums, mid+1, e)
	);
}

void print(Node *n){
	deque<Node*> nodes = {n};
	string ans = "";
	while(nodes.size()){
		Node *n = nodes.front();
		nodes.pop_front();
		if(!n) continue;
		ans += to_string(n->value) + ", ";
		nodes.push_back(n->left);
		nodes.push_back(n->right);
	}
	cout << ans.substr(0, ans.size()-2) << endl;
}

signed main() {
	print(createBalancedBST({1, 2, 3, 4, 5, 6, 7}));

	return 0;
}