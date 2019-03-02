


class BinaryTree {
    public:
    struct Root {
        int value;
        Root* left_child;
        Root* right_child;
        Root* parent;
    };
 Root* root;
 int size_of_Tree;
 BinaryTree();
 void insert(int x); 
 Root* searchRecursive(int x); 
 Root* searchIterative(int x );
int size(); 
int minimum();  
int maximum();  
int depth(struct Root *node);  
void printInorder(struct Root* node);  
void printPreorder(struct Root* node); 
void printPostorder(struct Root* node); 
void Print_iterative();

};
