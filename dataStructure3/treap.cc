using namespace std;

struct TreapNod  { //node declaration
	int data;
	int priority;
	TreapNod* l, *r;
	TreapNod(int d) { //constructor
		this->data = d;
		this->priority = rand() % n;
		this->l= this->r = nullptr;
	}
	private:
	static const int n = pow(2, 30);
};

class Treap{
	public:
		Treap(){root = nullptr;}
		~Treap();
		void rotLeft(TreapNod* &);
		void rotRight(TreapNod* &);
		void insertNod(TreapNod* &,int);
		bool searchNod(TreapNod* &,int) const;
		void des(TreapNod* &);
		void displayTreap(TreapNod *root, int space = 0, int height =10)const;
		TreapNod* &getR() {return root;}
	private:
		TreapNod* root;
};
void Treap::rotLeft(TreapNod* &root) { //left rotation
	TreapNod* R = root->r;
	TreapNod* X = root->r->l;
	R->l = root;
	root->r= X;
	root = R;
}
void Treap::rotRight(TreapNod* &root) { //right rotation
	TreapNod* L = root->l;
	TreapNod* Y = root->l->r;
	L->r = root;
	root->l= Y;
	root = L;
}
void Treap::insertNod(TreapNod* &root, int d) { //insertion
	if (root == nullptr) {
		root = new TreapNod(d);
		return;
	}
	if (d < root->data) {
		insertNod(root->l, d);
		if (root->l != nullptr && root->l->priority > root->priority)
			rotRight(root);
	} else {
		insertNod(root->r, d);
		if (root->r!= nullptr && root->r->priority > root->priority)
			rotLeft(root);
	}
}
bool Treap::searchNod(TreapNod* &root,int key) const{
	if (root == nullptr)
		return false;
	if (root->data == key)
		return true;
	if (key < root->data)
		return searchNod(root->l, key);
	return searchNod(root->r, key);
}
void Treap::displayTreap(TreapNod *root, int space, int height) const{ //display treap
	if (root == nullptr)
		return;
	//space += height;
	displayTreap(root->l, space);
	cout << endl;
	for (int i = height; i < space; i++)
		cout << ' ';
	cout << root->data << "(" << root->priority << ")\n";
	//cout << endl;
	displayTreap(root->r, space);
}

Treap::~Treap(){
	des(root);
}

void Treap::des(TreapNod* &root){
	queue<TreapNod*> q;
	q.push(root);
	while(!q.empty()){
		TreapNod* cur = q.front();
		q.pop();
		if(cur->l != nullptr)
			q.push(cur->l);
		if(cur->r != nullptr)
			q.push(cur->r);
				delete cur;
	}
};
