#include <stdio.h>
#include <stdlib.h>
struct Node{
    int input;//kosongan untuk input input
    struct Node* next;//pointer untuk node selanjutnya
    struct Node* prev;//pointer untuk node sebelumnya
};
int main(){
int pilih,number;
char choice='y';
    struct Node* head = NULL;//Node head yang tidak mempunyai nilai /NULL
    beginning(&head);//memanggil fungsi beginning dengan mengirim &head 
    display(head);//menampilkan node
    insertafter(head);//memanggil fungsi insertafter dengan mengirim head
    display(head);//menampilkan node
    ending(&head);//memanggil fungsi ending dengan mengirim &head
    display(head);//menampilkan node
    while(choice=='Y'||choice=='y'){
    printf("\n1.delete head");
    printf("\n2.delete mid");
    printf("\n3.delete ending");
    printf("\n4.pop");
    printf("\nchose:");
    scanf("%d", &pilih);
    switch(pilih){
        case 1:
    deleteNode(&head, head);//pengapusan node pada index head
    printf("\nindex head berhasil didelete\n");
    display(head);//menampilkan node
    break;
    case 2:
       deleteNode(&head, head->next);//pengapusan node pada index mid
    printf("\nindex mid berhasil didelete\n");
    display(head);//menampilkan node
    break;
    case 3:
    deleteNode(&head, head->next->next);//pengapusan node pada index 2
    printf("\nindex ending berhasil didelete\n");
    display(head);//menampilkan node
    break;
    case 4:
    number=pop(&head,head,head);
      if (number==-1){
          printf("empty");//jika node kosong
      } 
      else {
          printf("pop element:%d\n",number);//element yang dihapus
      }
      display(head);
    break;
    }
       printf("\nagain?Y/N=");
    scanf(" %c",&choice);
        getchar();
}
}

void display(struct Node* node){
    while (node!=NULL){//jika node memiliki nilai 
    printf("%d ",node->input);//perulangan untuk menampilkan nilai input dari node
    node = node->next;
    }
}
void beginning(struct Node** head_ref){
  char choice='Y';
  int new_input;
    while(choice=='Y'||choice=='y'){//perulangan untuk input data
    printf("begin=");
    scanf("%d",&new_input);
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));//membuat alokasi node
    new_node->input=new_input;//nilai new_input dimasukkan ke input dari new node
    new_node->next=(*head_ref);//next dari new_node adalah *head_ref 
    new_node->prev=NULL;//new node pada prev tidak mempunyai nilai(null)
 
    if((*head_ref)!=NULL)//jika head memiliki nilai 
    (*head_ref)->prev=new_node;
    (*head_ref)=new_node;//setiap ada inputan baru akan menjadi head
    printf("\nagain?Y/N=");
    scanf(" %c",&choice);
    getchar();
    }
}
void ending(struct Node** head_ref){
    int new_input;
    char choice='Y';
    while(choice=='Y'||choice=='y'){//perulangan  untuk input data
    printf("\nending=");
    scanf("%d",&new_input);
   struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));//membuat alokasi node
    struct Node *last =*head_ref;
    new_node->input=new_input;//nilai new_input dimasukkan ke input dari new_node
    new_node->next=NULL;//next dari new_node tidak mempunyai nilai (NULL)
    if(*head_ref==NULL){//jika head_ref ti3dak mempunyai nilai maka head ref menjadi new_node 
        new_node->prev=NULL;
        *head_ref=new_node;
        return;
    }
        while (last->next!= NULL){//perulangan untuk memindahkan node sampai akhir
        last =last->next;
          }
    
    last->next=new_node;//next dari last adalah new node
    new_node->prev=last;//new node prev adalah last jadi (saling tersambung)
    printf("again?Y/N=");
    scanf(" %c",&choice);
}
}
void insertafter(struct Node* prev_node){
        int new_input;
        char choice='y';
    if (prev_node == NULL){//jika prev node tidak memiliki nilai maka return
        printf("nope");
        return;
    }
	while(choice=='Y'||choice=='y'){//perulangan input dara
    struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));//membuat alokasi new_node
    printf("\ninsert after begin=");
    scanf("%d",&new_input);
    new_node->input=new_input;//nilai new_input dimasukkan ke input dari new_node
    new_node->next=prev_node->next;//nilai new_node->next adalah prev_node->next
    prev_node->next=new_node;//nilai prev_nde->next adalah new_node
    new_node->prev=prev_node;//new_node->prev adalah prev_node (saling tersambung)
    if(new_node->next!=NULL)//jika next dari new_node tidak sama dengan null maka
    new_node->next->prev=new_node;//ubah prev dari new_node ke new_node berikutnya
    printf("again?Y/N=");
    scanf(" %c",&choice);
        getchar();
        
    } 
}
void deleteNode(struct Node** head,struct Node* deleteNode_node){
    if(*head==NULL||deleteNode_node==NULL)//jika head dan deleteNode_node tidak memiliki nilai maka return
        return;
     
    if (*head == deleteNode_node)
        *head = deleteNode_node->next;//delete head
 
    /* Change next only if node to be deleted is NOT the last node */
    if (deleteNode_node->next != NULL)//delete first node
        deleteNode_node->next->prev = deleteNode_node->prev;
    if(deleteNode_node->prev!=NULL)//delete last npde
        deleteNode_node->prev->next=deleteNode_node->next;
     	 free(deleteNode_node);
}
int pop(struct Node** head,struct Node* node,struct Node *temp) {
int number;

if (*head==NULL) {
    return -1;
}
else {
    // struct node *prev;
    node = *head;//nilai new_node adalah *head
    temp = NULL;//temp tidak memiliki nilai

    while (node->next != NULL) {
        temp = node;
        node = node->next;
    }

    number = node->input;//nilai number adalah input dari node 
    if (temp == NULL) {
        *head = NULL;//jika temp tidak memiliki nilai maka *head di null kan
    }
    else {
        temp->next = node->next;//delete node 
    }

    return number;
}
}
