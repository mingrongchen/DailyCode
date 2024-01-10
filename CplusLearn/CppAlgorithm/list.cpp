#include<iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
    public:
    LinkedList() : head(nullptr) {}


    // 在链表末尾插入节点
    void insertAtEnd(T value) {
        // new memory
        Node<T>* newNode = new Node<T>(value);

        if (!head) {
            head = newNode;
        } else {
            Node<T>* current = head;

            while (current->next) {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    // 在链表指定位置插入节点
    void insertAtPosition(T value, int position) {
        // new memory
        Node<T>* newNode = new Node<T>(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* current = head;
            // 头节点不为空时，指向第position个节点
            for (int i = 0; i < position - 1 && current; ++i) {
                current = current->next;
            }

            // 前插
            if (current) {
                newNode->next = current->next;
                current->next = newNode;
            } else {
                std::cerr << "Invalid position" << std::endl;
            }
        }
    }

    // 删除链表指定位置的节点
    void deleteAtPosition(int position) {
        // 头节点为空，报错
        if (!head) {
            std::cerr << "List is empty" << std::endl;
            return;
        }

        Node<T>* temp = head;

        if (position == 0) {
            // 为0时，删除头节点
            head = head->next;
            delete temp;
        } else {
            Node<T>* current = head;
            // 找到position的节点
            for (int i = 0; i < position - 1 && current; ++i) {
                current = current->next;
            }

            if (current && current->next) {
                temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                std::cerr << "Invalid position" << std::endl;
            }
        }
    }

    // 查找节点的位置
    int find (T value) {
        Node<T>* current = head;
        int position = 0;

        while (current) {
            if (current->data = value) {
                return position;
            }

            current->next;
            position++;
        }

        // 返回-1表示未找到
        return -1;
    }

    void display() {
        Node<T>* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
        
    }

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;
        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    private:
        Node<T>* head;
};

int main() {
    LinkedList<int> intList;
    intList.insertAtEnd(1);
    intList.insertAtEnd(2);
    intList.insertAtEnd(3);
    intList.insertAtPosition(4, 1);
    intList.display();

    intList.deleteAtPosition(2);
    intList.display();

    int position = intList.find(2);
    if (position) {
        std::cout << "Element 2 found at position : " << position << std::endl;
    } else {
        std::cout << "Element 2 not found ." << std::endl;
    }

    return 0;
}