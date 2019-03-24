#include <vector>
template <typename V>
class Tree
{
public:
  struct Node
  {
    Node()
    {
      visited_print = false;
      visited_find = false;
    }
    bool visited_print;
    bool visited_find;
    V value;
    std::vector<Node *> children;
    Node *parent;
    bool was_visited_print()
    {
      return (visited_print);
    }

    void we_visit_print()
    {
      visited_print = true;
    }
    bool was_visited_find()
    {
      return (visited_find);
    }

    void we_visit_find()
    {
      visited_find = true;
    }
  };
  Tree();
  Tree(const Tree &tree);
  void insert(V x);
  int size() const;
  Node *return_root() const;
  void print();
  Tree swap(Tree swap, V parent1, V value1, V parent2, V value2);
  Node *find_node(V parent, V value);
  void catch_node(V parent, V value);

private:
  Node *root;
  int size_of_Tree;
};