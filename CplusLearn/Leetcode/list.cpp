#include<iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// 打印链表函数
void printList(ListNode* head) {
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }

    std::cout << std::endl;
    
}

// Leetcode 25 反转链表
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head == nullptr)
    {
        return head;
    }

    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;    // 保存下一个节点
        current->next = prev;    //将当前节点的指针反转
        prev = current;    //移动到下一个节点
        current = nextNode;    //移动到下一个节点
    }

    // prev现在是反转后的头结点
    return prev;
}

// Leetcode 206 反转链表递归
ListNode* reverseListRecur(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* last = reverseListRecur(head->next);
    head->next->next = head;
    head->next = nullptr;

    return last;    
}

// 反转链表测试
void reverseListTest() {
    // 创建一个简单的链表：1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "原始链表: ";
    printList(head);

    // 反转链表
    // head = reverseList(head);
    head = reverseListRecur(head);

    std::cout << "反转后链表: ";
    printList(head);

    // 释放内存
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}


int main() {
    reverseListTest();


    return 0;
}