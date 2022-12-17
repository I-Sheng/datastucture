#ifndef STD
#define STD

using namespace std;
#endif
template<typename type>
class Stack{
	public:
		Stack(int size);
		~Stack();
		void push(type val);
		void pop();
		type top() const;
		bool empty() const {return cur <= 0;}
		int getSize() const {return cur;}
	private:
		type* arr;
		int cur = 0;
};

template<typename type>
Stack<type>::Stack(int size){
	arr = new type[size];
}

template<typename type>
Stack<type>::~Stack(){
	delete [] arr;
}

template<typename type>
void Stack<type>::push(type val){
	arr[cur++] = val;
}

template<typename type>
void Stack<type>::pop(){
	--cur;
}

template<typename type>
type Stack<type>::top() const{
	return arr[cur - 1];
}

class node{
	public:
		friend class Skiplist;
		node(int num, node* next = nullptr, node* down = nullptr): num(num), next(next), down(down){}
		int getNum() const {return num;}
	private:
		node* next;
		node* down;
		int num;
};

class Skiplist {
	public:
		Skiplist() {
			tail = new node(INT_MAX-1);
			head = new node(INT_MIN, tail);
			height = 1;
		}
		~Skiplist(){
			Stack<node*> st(height);
			node* cur = head;
			while(cur != nullptr){
				st.push(cur);
				cur = cur->down;
			}
			while(!st.empty()){
				cur = st.top();
				st.pop();
				while(cur != nullptr){
					node* tmp = cur;
					cur = cur->next;
					delete tmp;
				}
			}
		}

		void print() const{
			Stack<node*> st(height);
			node* cur = head;
			while(cur != nullptr){
				st.push(cur);
				cur = cur->down;
			}
			while(!st.empty()){
				cur = st.top();
				st.pop();
				while(1){
					if(cur != nullptr){
						cur = cur->next;
					}
					else{
						break;
					}
				}

			}
		}

		bool search(int target) {
			node* cur = head;
			while(cur != nullptr){
				if(target > cur->next->num)
					cur = cur->next;
				else if(target == cur->next->num)
					return true;
				else
					cur = cur->down;
			}
			return false;

		}

		void add_height(int newHieght){
			int add_time = newHieght - height;
			for(int i = 0;i < add_time;++i){
				node* tmp = new node(INT_MAX);
				tmp->down = tail;
				tail = tmp;
				node* tmp2 = new node(INT_MIN, tail);
				tmp2->down = head;
				head = tmp2;
			}
			height = newHieght;
		}

		void add(int val) {
			int times = 1;
			while(1){
				if(rand() % 2)
					++times;
				else
					break;
			}

			if(times > height)
				add_height(times);

			Stack<node*> st(height);

			node* cur = head;
			print();
			while(cur != nullptr){
				if(val > cur->next->num){
					cur = cur->next;
				}
				else{
					st.push(cur);
					cur = cur->down;
				}
			}
			node* tmp2 = nullptr;
			for(int i = 0;i < times;++i){
				cur = st.top();
				st.pop();
				node* tmp = new node(val, cur->next, tmp2);
				tmp2 = tmp;
				cur->next = tmp;
			}
		}

		bool erase(int val) {
			if(!search(val)) return false;
			Stack<node*> st(height);

			node* cur = head;
			node* d = nullptr;
			while(1){
				if(val > cur->next->num)
					cur = cur->next;
				else if(cur->next->num == val){
					d = cur->next;
					break;
				}
				else
					cur = cur->down;
			}
			while(d != nullptr){
				if(cur->next == d){
					cur->next = d->next;
					node* tmp = d;
					d = d->down;
					delete tmp;
					cur = cur->down;
				}
				else if(cur->num > val){
					cout << "here is bug" << endl;
					exit(1);
				}else{
					cur = cur->next;
				}
			}
			return true;
		}
	private:
		node* head;
		node* tail;
		int height;
};


class array_of_sorted_arrays{
	public:
		array_of_sorted_arrays();
		void insert(int);
		bool search(int) const;
		vector<int> merge(const vector<int>&, const vector<int>&) const;
		vector<vector<int>>& getV() {return v;}
	private:
		int usage;
		vector<vector<int>> v;
};

array_of_sorted_arrays::array_of_sorted_arrays(){
	usage = 0;
	v.resize(31);
}

void array_of_sorted_arrays::insert(int num){
	vector<int> tmp;
	tmp.push_back(num);
	for(int i = 0;i <= 30;++i){
		if(usage & 1 << i){
			tmp = merge(v[i], tmp);
			usage &= ~(1 << i);
			v[i].clear();
		}
		else{
			v[i] = tmp;
			usage |= 1 << i;
			break;
		}
	}
}

bool array_of_sorted_arrays::search(int target) const{
	for(int i = 0;i <= 30;++i){
		if(binary_search(v[i].begin(), v[i].end(), target))
			return true;
	}
	return false;
}

vector<int> array_of_sorted_arrays::merge(const vector<int>& v1, const vector<int>&v2) const{
	vector<int> v;
	int x = 0, y = 0;
	if(v1.size()!= v2.size()){
		cout << "v1 and v2 size are diff" << endl;
		exit(0);
	}
	while(1){
		if(x < v1.size() && y < v2.size()){
			if(v1[x] < v2[y])
				v.push_back(v1[x++]);
			else
				v.push_back(v2[y++]);
		}
		else if(x < v1.size()){
			v.push_back(v1[x++]);
		}
		else if(y < v2.size()){
			v.push_back(v2[y++]);
		}
		else{
			break;
		}
	}
	return v;
}


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
		void insert(TreapNod* &,int);
		bool search(TreapNod* &,int) const;
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
void Treap::insert(TreapNod* &root, int d) { //insertion
	if (root == nullptr) {
		root = new TreapNod(d);
		return;
	}
	if (d < root->data) {
		insert(root->l, d);
		if (root->l != nullptr && root->l->priority > root->priority)
			rotRight(root);
	} else {
		insert(root->r, d);
		if (root->r!= nullptr && root->r->priority > root->priority)
			rotLeft(root);
	}
}
bool Treap::search(TreapNod* &root,int key) const{
	if (root == nullptr)
		return false;
	if (root->data == key)
		return true;
	if (key < root->data)
		return search(root->l, key);
	return search(root->r, key);
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


struct bstnode{
	int data;
	bstnode *l, *r;
	bstnode(int data) : data(data), l(nullptr), r(nullptr){}
};


class BST{
	public:
		BST(){if(root != nullptr) root = nullptr;}
		~BST();
		void insert(int);
		bool search(int) const;
		void des(bstnode* root);
	private:
		bstnode* root;
};

BST::~BST(){
	des(root);
}

void BST::des(bstnode* root){
	queue<bstnode*> q;
	q.push(root);
	while(!q.empty()){
		bstnode* cur = q.front();
		q.pop();
		if(cur->l != nullptr)
			q.push(cur->l);
		if(cur->r != nullptr)
			q.push(cur->r);
		delete cur;
	}
	//cout << "des complete" << endl;
};

void BST::insert(int val){
	//cout << val << " " << root << endl;
	if(root == nullptr){
		root = new bstnode(val);
		return;
	}
	//cout << (root->data) << "  "  <<  root << endl;
	//cout << (root->data) << "  "  <<  root << endl;
	bstnode* cur = root;
	while(1){
		if(val > cur->data){
			if(cur->r != nullptr){
				cur = cur->r;
			}
			else{
				cur->r = new bstnode(val);
				break;
			}
		}
		else{
			if(cur->l != nullptr){
				cur = cur->l;
			}
			else{
				cur->l = new bstnode(val);
				break;
			}
		}
	}
}

bool BST::search(int val) const{
	bstnode* cur = root;
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
