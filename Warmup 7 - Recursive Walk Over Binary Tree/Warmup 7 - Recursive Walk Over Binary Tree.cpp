#include <iostream>
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {}
};
void PrintTreePre(Node* root)
{
    char buf[16];
    sprintf_s(buf, "%d", root->data);
    std::cout << buf << std::endl;

    if (root->left != nullptr)
        PrintTreePre(root->left);
    if (root->right != nullptr)
        PrintTreePre(root->right);
}
void PrintTreePost(Node* root)
{
    if (root->left != nullptr)
        PrintTreePost(root->left);
    if (root->right != nullptr)
        PrintTreePost(root->right);
    char buf[16];
    sprintf_s(buf, "%d", root->data);
    std::cout << buf << std::endl;
}
void DeleteTree(Node* root)
{
    Node* left = root->left != nullptr ? root->left : nullptr;
    Node* right = root->right != nullptr ? root->right : nullptr;
    delete root;
    
    if (left != nullptr)
        DeleteTree(left);
    if (left != nullptr)
        DeleteTree(right);
}
int main(int argc, char** argv)
{
    /************************
               50
       20             70
     10   30        60  80
    ************************/
    Node* root = new Node(50,
        new Node(20, new Node(10), new Node(30)),
        new Node(70, new Node(60), new Node(80))
    );
    std::cout << "PrePrint" << std::endl;
    PrintTreePre(root);
    // pre - 50, 20, 10, 30, 70, 60, 80
    std::cout << std::endl << std::endl << "PostPrint" << std::endl;
    PrintTreePost(root);
    // post - 10, 30, 20, 60, 80, 70, 50

    DeleteTree(root);
    while (1);
    return 0;
}