struct Node {
    int key;
    int val;
    Node* left;
    Node* right;

    Node(int key, int value): key(key), val(value), left(nullptr), right(nullptr) {}
};

class TreeMap {

public:
    Node* root;
    TreeMap(): root(nullptr){}

    Node* search(Node* node, int key){
        if(!node){
            return nullptr;
        }
        if(key < node->key){
            return search(node->left, key);
        }
        if(key > node->key){
            return search(node->right, key);
        }
        return node;
    }

    Node* insert(Node* node, int key, int val){
        if(!node){
            return new Node(key, val);
        }

        if(key > node->key){
            node->right = insert(node->right, key, val);
        }else if(key < node->key){
            node->left = insert(node->left, key, val);
        }else{
            node->val = val;
        }

        return node;
    }

    void insert(int key, int val) {
        if(!root){
            root = new Node(key, val);
        }else{
            insert(root, key, val);
        } 
    }

    int get(int key) {
        Node* node = search(root, key);
        return (node) ? node->val : -1;
    }

    Node* getMinNode(Node* node){
        Node* cursor = node;
        while(cursor && cursor->left){
            cursor = cursor->left;
        }
        return cursor;
    }

    Node* getMaxNode(Node* node){
        Node* cursor = node;
        while(cursor && cursor->right){
            cursor = cursor->right;
        }
        return cursor;
    }

    int getMin() {
        if(!root) return -1;
        Node* minNode = getMinNode(root);
        return minNode->val;
    }

    int getMax() {
        if(!root) return -1;
        Node* maxNode = getMaxNode(root);
        return maxNode->val;
    }

    // Remove a node and return the root of the tree.
    Node* remove(Node* root, int val) {
        if (!root) {
            return nullptr;
        }

        if (val > root->key) { 
            root->right = remove(root->right, val);
        } else if (val < root->key) {
            root->left = remove(root->left, val);
        } else {
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            } else {
                Node* minNode = getMinNode(root->right);
                root->key = minNode->key;
                root->val = minNode->val;
                root->right = remove(root->right, minNode->key);
            }
        }
        return root;
    }

    void remove(int key) {
        root = remove(root, key);
    }

    void inorder(Node* node, std::vector<int>& keys) {
        if (!node) return;
        inorder(node->left, keys);
        keys.push_back(node->key);
        inorder(node->right, keys);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> keys;
        inorder(root, keys);
        return keys;
    }
};
