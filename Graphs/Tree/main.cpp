#include "Tree.cpp"
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <experimental/random>

void Create_Trees(int max_number_of_trees, int max_size_of_tree);
int main()
{
    Create_Trees(45, 20);
}
void Create_Trees(int max_number_of_trees, int max_size_of_tree)
{
    int parent_tree1;
    int value_tree1;
    int parent_tree2;
    int value_tree2;
    Tree<int> tree[max_number_of_trees];
    int number_of_trees = std::experimental::randint(1,max_number_of_trees);
    std::vector<Tree<int>> Trees;
    for (int i = 0; i < number_of_trees; i++)
    {
        for (int j = 0; j < max_size_of_tree; j++)
        {
            tree[i].insert(std::experimental::randint(1,max_size_of_tree*100));
        }
        Trees.push_back(tree[i]);
    }
    std::cout << Trees.size();
    std::cout << "\n";
    int index1 = std::experimental::randint(0,(int)Trees.size()-1);
    int index2 = std::experimental::randint(0,(int)Trees.size()-1);
    Trees[index1].print();
    std::cout << "\n";
    Trees[index2].print();
    std::cout << "\n";
    std::cout << "Define first node to be swapped: value of the parent then value of node\n";
    std::cin >> parent_tree1;
    std::cin >> value_tree1;
    std::cout << "Define second node to be swapped: value of the parent then value of node\n";
    std::cin >> parent_tree2;
    std::cin >> value_tree2;
    Trees[index1].swap(Trees[index2], parent_tree1, value_tree1, parent_tree2, value_tree2);
   Trees[index1].unprint();
   Trees[index2].unprint();
    Trees[index1].print();
    std::cout << "\n";
    Trees[index2].print();




}