#include <iostream>
#include <algorithm> // Thư viện chứa hàm max()
using namespace std;

#define NODES_SIZE 100 // Định nghĩa kích thước mảng chứa các node

// Cấu trúc của một node trong cây, sử dụng mô hình first-child/next-sibling
struct treeNode {
    int data;             // Dữ liệu của node
    treeNode* firstChild; // Con đầu tiên (tượng trưng cho cây con bên trái)
    treeNode* nextSibling;// Node anh em kế tiếp (tượng trưng cho cây con bên phải)

    // Hàm khởi tạo, khởi tạo dữ liệu và đặt con trỏ con, anh em bằng nullptr
    treeNode(int value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
};

// Lớp Tree để quản lý cây và các thao tác trên cây
class Tree {
public:
    treeNode* root;                // Gốc của cây
    treeNode* nodeList[NODES_SIZE]; // Mảng lưu trữ các node theo chỉ số
    bool isChild[NODES_SIZE];       // Mảng đánh dấu xem node đó có phải là con của node khác không

    // Hàm khởi tạo của lớp Tree
    Tree() : root(nullptr) {
        // Khởi tạo tất cả các phần tử trong nodeList và isChild
        for (int i = 0; i < NODES_SIZE; i++) {
            nodeList[i] = nullptr;
            isChild[i] = false;
        }
    }

    // Hàm cập nhật gốc cây: Node không được đánh dấu là con sẽ là gốc
    void updateRoot() {
        for (int i = 0; i < NODES_SIZE; i++) {
            if (nodeList[i] != nullptr && !isChild[i]) {
                root = nodeList[i];
                return;
            }
        }
    }

    // Hàm thêm một node con vào cây theo dạng first-child/next-sibling
    void addChild(int parent, int child) {
        // Nếu node cha chưa tồn tại, tạo mới
        if (nodeList[parent] == nullptr)
            nodeList[parent] = new treeNode(parent);

        // Nếu node con chưa tồn tại, tạo mới
        if (nodeList[child] == nullptr)
            nodeList[child] = new treeNode(child);

        // Lấy node cha và node con từ mảng
        treeNode* parentNode = nodeList[parent];
        treeNode* childNode = nodeList[child];

        // Nếu node cha chưa có con nào, đặt childNode làm con đầu tiên
        if (!parentNode->firstChild) {
            parentNode->firstChild = childNode;
        } else {
            // Nếu đã có con, duyệt danh sách các anh em và thêm childNode vào cuối danh sách
            treeNode* temp = parentNode->firstChild;
            while (temp->nextSibling) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = childNode; // Thêm node con vào cuối danh sách anh em
        }

        isChild[child] = true; // Đánh dấu node con
        updateRoot(); // Cập nhật lại gốc cây nếu cần
    }

    // Hàm tính chiều cao của cây từ node gốc truyền vào
    int treeHeight(treeNode* root) {
        // Nếu node rỗng, chiều cao bằng 0
        if (root == nullptr)
            return 0;
        
        int maxChildHeight = 0;
        // Duyệt qua tất cả các con của node hiện tại và tính chiều cao của từng cây con
        for (treeNode* child = root->firstChild; child != nullptr; child = child->nextSibling) {
            maxChildHeight = max(maxChildHeight, treeHeight(child));
        }
        // Chiều cao của node hiện tại = 1 (chính node đó) + chiều cao lớn nhất của các cây con
        return maxChildHeight + 1;
    }

    // Hàm duyệt tiền thứ tự (Preorder Traversal)
    void preOrder(treeNode* root) {
        if (!root)
            return;
        // In dữ liệu của node hiện tại trước
        cout << root->data << " ";
        // Duyệt cây con đầu tiên
        preOrder(root->firstChild);
        // Duyệt các anh em kế tiếp
        preOrder(root->nextSibling);
    }

    // Hàm duyệt hậu thứ tự (Postorder Traversal)
    void postOrder(treeNode* root) {
        if (!root)
            return;
        // Duyệt cây con đầu tiên
        postOrder(root->firstChild);
        // Duyệt các anh em kế tiếp
        postOrder(root->nextSibling);
        // In dữ liệu của node hiện tại sau khi duyệt con
        cout << root->data << " ";
    }

    // Hàm kiểm tra xem cây có phải là cây nhị phân hay không (tối đa 2 con cho mỗi node)
    bool Binary_check(treeNode* root) {
        if (!root)
            return true;

        // Đếm số lượng con của node hiện tại
        int childCount = 0;
        treeNode* temp = root->firstChild;
        while (temp) {
            childCount++;
            temp = temp->nextSibling;
        }
        
        // Nếu số lượng con lớn hơn 2, không phải cây nhị phân
        if (childCount > 2)
            return false;

        // Đệ quy kiểm tra từng node con
        treeNode* child = root->firstChild;
        while (child) {
            if (!Binary_check(child))
                return false;
            child = child->nextSibling;
        }
        return true;
    }

    // Hàm duyệt trung thứ tự (Inorder Traversal)
    // Giả sử: firstChild là con trái, nextSibling là con phải
    void inOrder(treeNode* root) {
        if (!root)
            return;
        // Duyệt cây con bên trái
        inOrder(root->firstChild);
        // In dữ liệu của node hiện tại
        cout << root->data << " ";
        // Duyệt cây con bên phải
        inOrder(root->nextSibling);
    }
};

int main() {
    Tree tree;
    int N,M;
    cin>>N>>M;
    for (int i=0; i<M ;i++)
    {
        int parent, child;
        cin>>parent>>child;
        tree.addChild(parent , child);
    }
    
    // Tính và in chiều cao của cây
    cout << tree.treeHeight(tree.root) << endl;
    
    // Duyệt tiền thứ tự (preorder)
    tree.preOrder(tree.root);
    cout << endl;
    
    // Duyệt hậu thứ tự (postorder)
    tree.postOrder(tree.root);
    cout << endl;
    
    // Kiểm tra xem cây có phải là cây nhị phân hay không và nếu đúng, duyệt trung thứ tự (inorder)
    if (tree.Binary_check(tree.root)) {
        tree.inOrder(tree.root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }
    return 0;
}
