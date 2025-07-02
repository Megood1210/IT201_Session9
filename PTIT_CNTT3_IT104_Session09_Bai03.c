#include<stdio.h>
#include<stdlib.h>
// Định nghĩa kiểu dữ liệu Node
typedef struct Node{
    int data;
    struct Node *next;
}Node;
// Hàm thêm node vào đầu danh sách
Node* addToHead(Node* head, int value){
    Node* newNode = (Node*) malloc(sizeof (Node)); // Cấp phát bộ nhớ cho 1 node mới
    if (newNode == NULL){
        printf("Khong the tao node moi");
        exit(1);
    }
    newNode->data = value; // Gán giá trị cho node
    newNode->next = NULL; // Trỏ node mới về node đầu hiện tại

    return newNode;
}

// Hàm duyệt danh sách và in dữ liệu từng phần tử
void traverseList(Node* head){
    Node* temp = head;
    int position = 1;
    if (temp == NULL){
        printf("Danh sach rong");
        return;
    }
    while (temp != NULL){
        printf("%d -> ", position, temp->data);
        temp = temp->next;
        position++;
    }
    printf("NULL");
}
// Hàm tìm kiếm giá trị trong danh sách liên kết đơn
void searchList(Node* head, int value){
    Node* temp = head;
    int found = 0;
    int position = 1;
    while (temp != NULL){
        if (temp->data == value){
            printf("True");
            found = 1;
        }
        temp = temp->next;
        position++;
    }
    if (!found){
        printf("False");
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách với 5 phần tử bất kỳ
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        Node* newNode = addToHead(head, values[i]);
        if (head == NULL){
            head = tail = newNode; // Phần tử đầu tiên
        }else{
            tail->next = newNode; // Nối vào cuối danh sách
            tail = newNode;
        }
    }
    traverseList(head);
    // Nhập số cần tìm
    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    searchList(head, x);
    return 0;
}
