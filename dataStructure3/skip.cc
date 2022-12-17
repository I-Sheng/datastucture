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
// # Yilan: 初始化列表順序反了，要依照宣告順序 (Warning)
                int getNum() const {return num;}
        private:
                node* next;
                node* down;
                int num;
};

class Skiplist {
        public:
                Skiplist() {
// # Yilan: tail 是空的，表示 head->next 也是空的 (Error)
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
                                                cout << cur->num << " ";
                                                cur = cur->next;
                                        }
                                        else{
                                                cout << endl;
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

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
