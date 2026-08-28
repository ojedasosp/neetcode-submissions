class DynamicArray {
public:

    int capacity;
    int size;
    int* store;

    DynamicArray(int capacity) {
        this->capacity = (capacity > 0) ? capacity : 0;
        this->size = 0;
        store = new int[capacity]();
    }

    ~DynamicArray(){
        delete[] store;
    }

    int get(int i) {
        return store[i];
    }

    void set(int i, int n) {
        store[i] = n;
    }

    void pushback(int n) {
        if(size == capacity){
            resize();
        }
        store[size] = n;
        size++;
    }

    int popback() {
        size--;
        return store[size];
    }

    void resize() {
        int newCapacity = capacity*2;
        int* newStore = new int[newCapacity];
        for(int i = 0; i < capacity; i++){
            newStore[i] = store[i];
        }
        delete[] store;
        store = newStore;
        capacity = newCapacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
