using namespace std;
struct node{
	int data;
	node *l, *r;
	node(int data) : data(data), l(NULL), r(NULL){}
};


class BST{
	public:
		BST(){}
		~BST();
		void insert(int);
		bool search(int) const;
		void des(node* root);
	private:
		node* root;
};

BST::~BST(){
	des(root);
}

void BST::des(node* root){
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* cur = q.front();
		q.pop();
		if(cur->l != nullptr)
			q.push(cur->l);
		if(cur->r != nullptr)
			q.push(cur->r);
				delete cur;
	}
};

void BST::insert(int val){
	if(root == nullptr){
		root = new node(val);
		return;
	}
	node* cur = root;
	while(1){
		if(val > cur->data){
			if(cur->r != nullptr){
				cur = cur->r;
			}
			else{
				cur->r = new node(val);
				break;
			}
		}
		else{
			if(cur->l != nullptr){
				cur = cur->l;
			}
			else{
				cur->l = new node(val);
				break;
			}
		}
	}
}

bool BST::search(int val) const{
	node* cur = root;
	while(1){
		if(cur == nullptr)
			return false;
		else if(val > cur->data)
			cur = cur->r;
		else if(val < cur->data)
			cur = cur->l;
		else if(val == cur->data)
			return true;
		else
			cout << "here is bug in BST search" << endl;
	}
}
