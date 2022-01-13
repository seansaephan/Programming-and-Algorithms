//bst.h
//Saephan, Sean
//sksaephan
#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
using namespace std;

class Bst {
public:
  Bst();
  bool insert(string str);
  bool find(string value);
  // Depth-first, in-order traversal, returning values via a vector.
  void dft(vector<string> &values);
  // Breadth-first traversal, returning values via a vector.
  void bft(vector<string> &values);
  int size();
  bool balanced();
  void rebalance();
  double average_distance_to_root();
  

private:
  class Node {
  public:
    Node(string str){m_str = str; m_left = NULL; m_right = NULL;}
    ~Node(){delete m_left; delete m_right;}
    string m_str;
    Node *m_left;
    Node *m_right;
  };

  Node *m_root;
  int m_size;
  bool insert(string str, Node *root);
  bool find(string str, Node *root);
  void dft(vector<string> &values, Node *root);
  int balanced(Node *root);
  bool rebalance(Node *root);
  void average_distance_to_root(int cur_distance, int &node_count, int& distances_sum, Node *root);
  void insert_from_vector(vector<string> &elements, int start, int end);
  int size(Node *root);
};
#endif
