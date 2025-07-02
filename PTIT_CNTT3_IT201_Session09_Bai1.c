#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm tạo phần tử mới
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm tạo danh sách liên kết với 5 phần tử
struct Node* createLinkedList() {
    struct Node* head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    return head;
}

// Hàm in danh sách (để kiểm tra)
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createLinkedList();
    printf("Danh sách liên kết: ");
    printList(head);

    // Giải phóng bộ nhớ
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}