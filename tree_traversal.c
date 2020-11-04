#include<stdio.h>
#include<stdlib.h>

//queue functions
/*
        1
    2       3
4       5 6     7
*/
struct node
{
    struct node* next;
    struct t_node* data;
};

struct node* new_qNode(struct t_node* x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=x;
    return temp;
}
//queue functions


//trees function
struct t_node
{
    struct t_node* left;
    struct t_node* right;
    int data;
};

struct t_node* new_tNode(int x)
{
    struct t_node* temp=(struct t_node*)malloc(sizeof(struct t_node));
    temp->left=temp->right=NULL;
    temp->data=x;
    return temp;
}

void Inorder(struct t_node* root)
{//LNR
    if(!root)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder((root->right));
}

void Preorder(struct t_node* root)
{
    //NLR
    if(!root)
        return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct t_node* root)
{
    if(!root)
        return;
    Postorder(root->left);
    Postorder((root->right));
    printf("%d ",root->data);
}


/*
1.       1
2.   2       3
3.4      5
Inorder:4 2 5 1 3
*/
//trees function
int main()
{
    printf("NOTE:For tree input take -1 as NULL\n\n");
    struct t_node* root=NULL;
    int x,lc,rc;
    printf("Enter root node data: ");
    scanf("%d",&x);
    root=new_tNode(x);
    //queue
    struct node* head=new_qNode(root);
    struct node* tail=head;//rear pointer
    while(head)
    {
        struct t_node* temp=head->data;
        printf("Enter left child of %d: ",temp->data);
        scanf("%d",&lc);
        if(lc!=-1)
        {
            //tree Linking Nodes
            temp->left=new_tNode(lc);
            //tree
            //queue
            tail->next=new_qNode(temp->left);
            tail=tail->next;
            //queue
        }
        printf("Enter right child of %d: ",temp->data);
        scanf("%d",&rc);
        if(rc!=-1)
        {
            //tree linking
            temp->right=new_tNode(rc);
            //tree
            //queue
            tail->next=new_qNode(temp->right);
            tail=tail->next;
            //queue
        }
        struct node* t=head;
        head=head->next;
        free(t);
    }
    int c=1,choice;
    while(c)
    {
        printf("1.In-order Traversal\n2.Pre-order Traversal\n3.Post-order traversal\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("In-order Traversal: ");
                Inorder(root);
                break;
            }
            case 2:
            {
                printf("Pre-order Traversal: ");
                Preorder(root);
                break;
            }
            case 3:
            {
                printf("Post-order Traversal: ");
                Postorder(root);
                break;
            }
            case 4:
            {
                c=0;
                break;
            }
            default:
            {
                printf("Invalid choice!!!!Try again!!!!\n");
            }
        }
        printf("\n");
    }
    return 0;
}
