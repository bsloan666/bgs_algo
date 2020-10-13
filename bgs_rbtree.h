#include <iostream>

template <typename KeyType, typename ValueType>
class RBTree {
    enum {
        BLACK,
        RED
    };
    public:
    class Node {
        public:
        Node(KeyType _key, ValueType _value):
            key(_key), value(_value), color(0), 
            parent(nullptr), left(nullptr), right(nullptr){}

        KeyType key;
        ValueType value;
        bool color;
        Node *parent;
        Node *left;
        Node *right;
    };
    void insert(Node *root, Node *n);
    void destroy(KeyType _key);
    void find(KeyType key);

    
    private:
    Node *get_parent(Node *n);
    Node *get_grandparent(Node *n);
    Node *get_sibling(Node *n);
    Node *get_uncle(Node *n);
    void rotate_left(Node *n);
    void rotate_right(Node *n);
    Node *insert(Node *root, Node *n);
    Node *insert_recurse(Node *root, Node *n);
    void insert_repair_tree(Node *n);
    void insert_case_1(Node *n);
    void insert_case_2(Node *n);
    void insert_case_3(Node *n);
    void insert_case_4(Node *n);
    void insert_case_4_step_2(n);
    Node *m_root;
};

template <typename KeyType, typename ValueType>
Node *RBTree::get_parent(Node *n){
    return n != nullptr? n->parent: nullptr;
}


template <typename KeyType, typename ValueType>
Node *RBTree::get_grandparent(Node *n){
    return get_parent(get_parent(p)
}


template <typename KeyType, typename ValueType>
Node *RBTree::get_sibling(Node *n){
    Node *p = get_parent(n);

    if(p == nullptr) {
        return nullptr;
    }
    if(n == p->left) {
        return p->right;
    } else {
        return p->left;
    }

}


template <typename KeyType, typename ValueType>
Node *RBTree::get_uncle(Node *n){
    Node *p = get_parent(n);

    return get_sibling(p);
}


template <typename KeyType, typename ValueType>
void RBTree::rotate_left(Node *n){
    Node * nnew = n->right;
    Node * p = get_parent(n);
    assert(nnew != nullptr);

    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;
   
    if (n->right != nullptr) {
        n->right->parent = n;
    }

    if (p != nullptr) {
        if (n == p->left) {
            p->left = nnew;
        } else if (n == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}


template <typename KeyType, typename ValueType>
void RBTree::rotate_right(Node *n){
    Node* nnew = n->left;
    Node* p = get_parent(n);
    assert(nnew != nullptr);
                           

    n->left = nnew->right;
    nnew->right = n;
    n->parent = nnew;

    if (n->left != nullptr) {
        n->left->parent = n;
    }

    if (p != nullptr) {
        if (n == p->left) {
            p->left = nnew;
        } else if (n == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}

template <typename KeyType, typename ValueType>
Node *RBTree::insert(Node *root, Node *n) {
    insert_recurse(root, n);
    insert_repair_tree(n);
    root = n;
    while (get_parent(root) != nullptr) {
        root = get_parent(root);
    }
    return root;
}

template <typename KeyType, typename ValueType>
void RBTree::insert_recurse(Node *root, Node *n) {
    if(root != nullptr) {
        if(n->key < root->key) {
            if(root->left != nullptr) {
                insert_recurse(root->left, n);
                return;

            } else {
                root->left = n;
            }
        } else {
            if(root->right != nullptr) {
                insert_recurse(root->right, n);
                return
            } else {
                root->right = n;
            }
        }
    }
    n->parent = root;
    n->left = nullptr;
    n->right = nullptr;
    n->color = RED;
}

template <typename KeyType, typename ValueType>
void RBTree::insert_repair_tree(Node *n) {
    if (get_parent(n) == nullptr) {
        insert_case_1(n);
    } else if (get_parent(n)->color == BLACK) {
        insert_case_2(n);
    } else if (get_uncle(n) != nullptr && get_uncle(n)->color == RED) {
        insert_case_3(n);
    } else {
        insert_case_4(n);
    }
}

template <typename KeyType, typename ValueType>
void RBTree::insert_case_1(Node *n){
    n->color = BLACK;
}

template <typename KeyType, typename ValueType>
void RBTree::insert_case_2(Node *n){
    return;
}

template <typename KeyType, typename ValueType>
void RBTree::insert_case_3(Node *n){
    get_parent(n)->color = BLACK;
    get_uncle(n)->color = BLACK;
    get_grandparent(n)->color = RED;
    insert_repair_tree(get_grandparent(n));
}

template <typename KeyType, typename ValueType>
void RBTree::insert_case_4(Node *n){
    Node* p = get_parent(n);
    Node* g = get_grandparent(n);

    if (n == p->right && p == g->left) {
        rotate_left(p);
        n = n->left;
    } else if (n == p->left && p == g->right) {
        rotate_right(p);
        n = n->right;
    }

    insert_case_4_step_2(n);
}


template <typename KeyType, typename ValueType>
void  RBTree::insert_case_4_step_2(n) {
    Node* p = get_parent(n);
    Node* g = get_grandparent(n);

    if (n == p->left) {
        rotate_right(g);
    } else {
        rotate_left(g);
    }
    p->color = BLACK;
    g->color = RED;
}
