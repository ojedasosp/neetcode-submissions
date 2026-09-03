struct Node {
    int key;
    int val;
    Node* next;
    Node(int k, int v): key(k), val(v), next(nullptr) {}
};

class HashTable {
public:
    vector<Node*> table;
    int capacity;
    int size;
    HashTable(int capacity): size(0) {
        table = vector<Node*>(capacity, nullptr);
        this->capacity = capacity;
    }

    int hash(int key){
        return key % capacity;
    }

    void insert(int key, int value) {
        int idx = hash(key);
        Node* node = table[idx];
        if(!node){
            table[idx] = new Node(key, value);
            size++;
        }else{
            Node* prev = nullptr;
            while (node) {
                if (node->key == key) {
                    node->val = value;
                    return;
                }
                prev = node;
                node = node->next;
            }
            prev->next = new Node(key, value);
            size++;
        }

        if((float) size / capacity >= 0.5){
            resize();
        }
    }

    int get(int key) {
        int idx = hash(key);
        Node* node = table[idx];
            while(node){
                if(key == node->key){
                    return node->val;
                }
                node = node->next;
            }
        return -1;
    }

    bool remove(int key) {
        int idx = hash(key);
        Node* node = table[idx];
        Node* prev = nullptr;

        while(node){
            if(node->key == key){
                if(prev){
                    prev->next = node->next;
                }else{
                    table[idx] = node->next;
                }
                delete node;
                size--;
                return true;
            }
            prev = node;
            node = node->next;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        int newCapacity = capacity * 2;
        vector<Node*> newTable(newCapacity, nullptr);

        for (Node* node : table) {
            while (node) {
                int index = node->key % newCapacity;
                if (!newTable[index]) {
                    newTable[index] = new Node(node->key, node->val);
                } else {
                    Node* newNode = newTable[index];
                    while (newNode->next) {
                        newNode = newNode->next;
                    }
                    newNode->next = new Node(node->key, node->val);
                }
                Node* toDelete = node;
                node = node->next;
                delete toDelete;
            }
        }
        capacity = newCapacity;
        table = newTable;
    }
};
