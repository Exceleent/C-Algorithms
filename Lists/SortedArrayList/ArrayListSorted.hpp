class SortedArrayList
{
  private:
    int *array;
    int nums;

  public:
    SortedArrayList();
    void push(int x);   // push element 'x'
    int pop();          // return and pop first element
    int erase(int i);   // erase element at position 'i' and return his value
    int find(int x);    // return position of element, or -1 if 'x' is not in list
    int size() const;   // return size of list
    void remove(int x); // remove all elements 'x'
    static SortedArrayList merge(const SortedArrayList &a, const SortedArrayList &b);
    // merge two list
    int getelement(int index) const; 
    void unique(); // Delete duplication
    void print();  
};
