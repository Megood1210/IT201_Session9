#include<stdio.h>
#include<stdlib.h>
// Định nghĩa kiểu dữ liệu Node
typedef struct Node{
    int data;
    struct Node *next;
}Node;
// Hàm thêm node vào đầu danh sách
Node* addToHead(int data){
    Node* newNode = (Node*) malloc(sizeof(Node)); // Cấp phát bộ nhớ cho 1 node mới
    if (newNode == NULL){
        printf("Khong the tao node moi");
        exit(1);
    }
    newNode->data = data; // Gán giá trị cho node
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
        printf("%d -> ",temp->data);
        temp = temp->next;
        position++;
    }
    printf("NULL");
}
// Hàm thêm mới phần tử vào vị trí bất kỳ
Node* addNode(Node* head, int position, int data){
    if (position < 1){
        printf("Vi tri khong hop le");
        return head;
    }
    Node* newNode = addToHead(data);

    // Chèn vào đầu danh sách
    if (position == 1){
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    int count = 1;
    // Duyệt đến node đứng trước vị trí cần chèn
    while (temp != NULL && count < position - 1){
        temp = temp->next;
        count++;
    }
    if (temp == NULL){
        printf("Vi tri khong hop le");
        free(newNode);
        return head;
    }
    // Chèn mode mới vào sau temp
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    // Tạo danh sách với 5 phần tử bất kỳ
    int values[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++){
        Node* newNode = addToHead(values[i]);
        if (head == NULL){
            head = tail = newNode; // Phần tử đầu tiên
        }else{
            tail->next = newNode; // Nối vào cuối danh sách
            tail = newNode;
        }
    }
    // In danh sách ban đầu
    traverseList(head);
    int value, position;
    // Nhập giá trị muốn thêm
    printf("\nvalue: ");
    scanf("%d", &value);
    // Nhập vị trí muốn thêm
    printf("\nposition: ");\
    scanf("%d", &position);
    // Gọi hàm thêm vào vị trí
    head = addNode(head, position, value);
    // In kết quả
    printf("\n");
    traverseList(head);

    return 0;
}

