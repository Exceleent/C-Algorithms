class SortedLinkedList {  // Klasa listy
    struct Node {       // Zagnieżdżona klasa węzła
        int x;          // Element przechowywany przez węzeł listy
        Node* prev;     // Wskaźnik do poprzedniego węzła
        Node* next;     // Wskaźnik do kolejnego węzła
    };
    public:
    int nums;
    SortedLinkedList();
    Node* head;         // Wskaźnik do pierwszego węzła
    Node* tail;         // Wskaźnik do ostatniego węzła
    void push(int x);   // Wstawia element 'x'
    int pop();          // Zwraca i usuwa pierwszy (najmniejszy) element
    int erase(int i);   // Usuwa element na pozycji 'i' i zwraca jego wartość
    int find(int x);    // Zwraca pozycję elementu o wartości 'x' lub -1 gdy nie znaleziono
    int size()const;         // Zwraca liczbę elementów w liście
    void remove(int x); // Usuwa wszystkie elementy równe 'x'
    static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
                        // Scala dwie posortowane listy i zwraca posortowaną listę
    int get(int) const;
    void unique();      // Usuwa sąsiadujące duplikaty
    void print();       // W                           // 

};

