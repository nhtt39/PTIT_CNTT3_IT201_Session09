#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct Node {
    int data;
    struct Node* next;
};

// Hàm thêm phần tử vào vị trí bất kỳ
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    int i = 0;

    while (current != NULL && i < position) {
        prev = current;
        current = current->next;
        i++;
    }

    prev->next = newNode;
    newNode->next = current;
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
    struct Node* head = NULL;
    int value, position;

    // Nhập giá trị và vị trí từ người dùng
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them: ");
    scanf("%d", &position);

    // Thêm phần tử vào vị trí được yêu cầu
    insertAtPosition(&head, value, position);

    // In danh sách
    printf("Danh sach lien ket sau khi them: ");
    printList(head);

    return 0;
}