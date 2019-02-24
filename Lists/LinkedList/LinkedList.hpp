class LinkedList
{
    struct Node
    {
        int x;
        Node *prev;
        Node *next;
    };

  public:
    LinkedList();
    Node *head;
    Node *tail;
    int list_size;
    void push_front(int x);
    int pop_front();
    void push_back(int x);
    int pop_back();
    int find(int x);
    int erase(int pos);
    int insert(int pos, int x);
    int listsize();
    bool empty();
    void print();
};
