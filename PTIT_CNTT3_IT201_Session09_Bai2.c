#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node cho danh sách liên kết
struct Node {
    int data;
    struct Node* next;
};

// Hàm tạo phần tử mới cho danh sách liên kết
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

// Hàm duyệt và in toàn bộ danh sách liên kết
void traverseList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Danh sách rỗng!\n");
        return;
    }
    printf("Dữ liệu của các phần tử trong danh sách liên kết:\n");
    int index = 1;
    while (current != NULL) {
        printf("Phần tử %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
}

// Hàm in danh sách liên kết
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Tạo danh sách liên kết với 5 phần tử
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // In danh sách
    printf("Danh sách liên kết: ");
    printList(head);

    // Duyệt và in dữ liệu từng phần tử
    traverseList(head);

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