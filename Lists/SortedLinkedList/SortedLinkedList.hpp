class SortedLinkedList {  // List Class
    struct Node {       //  Node Class
        int x;          // Element inside(value)
        Node* prev;     // Pointer to previous node
        Node* next;     // Pointer to next node
    };
    private:
    int nums; // size of list
    public:
    SortedLinkedList();
    Node* head;         // Pointer to first node
    Node* tail;         // Pointer to last node
    void push(int x);   // Push element 'x'
    int pop();          // return 'x' of head and pop head
    int erase(int i);   // remove node at'i' position and return his value 
    int find(int x);    // return position of 'x', or -1 if there is no such element in list 
    int size()const;   
    void remove(int x); // remove all elements with value 'x'
    static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
                        // merge two lists
    int get(int) const;
    void unique();      // Delete duplication
    void print();     

};

