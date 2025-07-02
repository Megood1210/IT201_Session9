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
Node* deleteNode(Node* head, int position)
{
    if (head == NULL){
        printf("Danh sach rong");
        return head;
    }
    if (position < 1){
        printf("Vi tri khong hop le");
        return head;
    }

    // Xóa phần tử đầu tiên
    if (position == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // Tìm node đứng trước vị trí cần xóa
    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1){
        temp = temp->next;
        count++;
    }
    // Nếu vị trí không hợp lệ
    if (temp == NULL || temp->next == NULL){
        printf("Vi tri khong hop le");
        return head;
    }
    // Xóa node tại vị trí
    Node* current = temp->next;
    temp->next = current->next;
    free(current);
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
    int position;
    // Nhập vị trí muốn xóa
    printf("\nposition: ");\
    scanf("%d", &position);
    // Gọi hàm xóa tại vị trí
    head = deleteNode(head, position);
    // In kết quả
    printf("\n");
    traverseList(head);

    return 0;
}

