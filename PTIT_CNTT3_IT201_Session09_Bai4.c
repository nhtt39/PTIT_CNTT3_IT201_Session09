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

// Hàm tìm kiếm phần tử trong danh sách liên kết
void searchNode(struct Node* head, int value) {
    struct Node* current = head;
    int index = 1;
    int found = 0;

    while (current != NULL) {
        if (current->data == value) {
            printf("Tìm thấy %d tại phần tử thứ %d\n", value, index);
            found = 1;
        }
        current = current->next;
        index++;
    }

    if (!found) {
        printf("Không tìm thấy %d trong danh sách liên kết\n", value);
    }
}

// Hàm đếm số lượng phần tử trong danh sách liên kết
int countNodes(struct Node* head) {
    struct Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
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

    int value;
    printf("Nhập một số nguyên dương để tìm kiếm: ");
    scanf("%d", &value);

    // Kiểm tra số nguyên dương
    if (value <= 0) {
        printf("Vui lòng nhập một số nguyên dương!\n");
    } else {
        // Tìm kiếm và in kết quả
        searchNode(head, value);
    }

    // Đếm và in số lượng phần tử
    int nodeCount = countNodes(head);
    printf("Số lượng phần tử trong danh sách liên kết: %d\n", nodeCount);

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