struct Node {
    int value;
    Node* prev;

    Node(int value, Node* prev): value(value), prev(prev) {}
};

class Deque {
public:

    Node* head;
    Node* tail;

    Deque(): head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return !head && !tail;
    }

    void append(int value) {
        Node* node = new Node(value, nullptr);
        if(!tail && !head){
            tail = node;
            head = node;
        }else{
            node->prev = tail;
            tail = node;
        }
    }

    void appendleft(int value) {
        Node* node = new Node(value, nullptr);
        if(!tail && !head){
            tail = node;
            head = node;
        }else{
            head->prev = node;
            head = node;
        }
    }

    int pop() {
        if(isEmpty()){
            return -1;
        }
        int tvalue = tail->value;
        if(tail == head){
            delete tail;
            tail = nullptr;
            head = nullptr;
        }else{
            Node* aux = tail->prev;
            delete tail;
            tail = aux;
        }
        return tvalue;
    }

    int popleft() {
        if(isEmpty()){
            return -1;
        }
        int hvalue = head->value;
        if(tail == head){
            delete head;
            tail = nullptr;
            head = nullptr;
        }else{
            Node* aux = tail;
            while(aux->prev != head){
                aux = aux->prev;
            }
            aux->prev = nullptr;
            delete head;
            head = aux;
        }
        return hvalue;
    }
};
