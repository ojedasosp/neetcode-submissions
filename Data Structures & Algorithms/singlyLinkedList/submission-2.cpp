struct Node {
    int value;
    Node* next;

    Node(int value, Node* next): value(value), next(next) {}
};

class LinkedList {
private:
    Node* getNode(int index){
        Node* node = head;
        for(int i = 0; i < len; i++){
            if(i == index){
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }
public:

    Node* head;
    Node* tail;
    int len;

    LinkedList(): head(nullptr), tail(nullptr), len(0) {}

    int get(int index) {
        if(((len-1) - index) < 0) return -1;
        Node* node = head;
        for(int i = 0; i < len; i++){
            if(i == index){
                return node->value;
            }
            node = node->next;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* newHead = new Node(val, nullptr);
        if(!head && !tail) {
            head = newHead;
            tail = newHead;  
        }else{
            newHead->next = head;
            head = newHead;
        }
        len++;
    }
    
    void insertTail(int val) {
        Node* newTail = new Node(val, nullptr);
        if(!tail && !head){
            tail = newTail;
            head = newTail;
        }else{
            tail->next = newTail;
            tail = newTail;
        }
        len++;
    }

    bool remove(int index) {
        if(((len-1) - index) < 0) return false;
        Node* tmp = head;
        for(int i=0; i < len; i++){
            if(index == i){
                if(tmp == head && !(tmp == tail)){
                    head = tmp->next;
                    delete tmp;
                    len--;
                    return true;
                }
                else if(tmp == tail && !(tmp == head)){
                    tail = getNode(i-1);
                    delete tmp;
                    len--;
                    return true;
                }else if((tmp == head) && (tmp == tail)){
                    head = nullptr;
                    tail = nullptr;
                    delete tmp;
                    len--;
                    return true;
                }
                Node* tmp2 = getNode(i-1);
                tmp2->next = tmp->next;
                delete tmp;
                len--;
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> values;
        for(int i=0; i<len;i++){
            values.push_back(get(i));
        }
        return values;
    }
};
