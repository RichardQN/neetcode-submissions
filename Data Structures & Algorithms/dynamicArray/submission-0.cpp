class DynamicArray {
public:
    int size;
    int cap;
    int *data;

    DynamicArray(int capacity) {
        cap = capacity;
        size = 0;
        data = new int[cap];
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size == cap){
            resize();
        }
        size++;
        data[size-1] = n; 
    }

    int popback() {
        size--;
        return data[size];
    }

    void resize() {
        int newcap = cap*2;
        int *newData = new int[newcap];
        for (int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cap = newcap;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
