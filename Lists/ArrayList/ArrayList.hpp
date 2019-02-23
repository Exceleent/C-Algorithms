
class ArrayList
{
  private:
    int *array;
    int lengtharray;
    int listsize;

  public:
    ArrayList();
    void resize();
    bool needtoresize();
    void push_front(int x);
    int pop_front();
    void push_back(int x);
    int pop_back();
    int find(int x);
    void erase(int);
    int size();
};
