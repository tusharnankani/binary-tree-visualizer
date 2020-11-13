#include<stdio.h>
#include<stdlib.h>
//8+8/2*3+8/2=23
//queue functions
/*                            L    I
            1                12   N
      2           3           6   11
   4     5     6     7        3   5
 8   9 1   1 1   1 1   1      1   3

                        1
            1                       1
      1           1           1           1
   1     1     1     1     1     1     1     1
 1   1 1   1 1   1 1   1 1   1 1   1 1   1 1    1
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
int q_size(struct node* head)
{
    if(!head)
        return 0;
    return 1+q_size(head->next);
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

int height(struct t_node* root)
{
    if(!root)
    {
        return 0;
    }
    int l,r;
    l=height(root->left);
    r=height(root->right);
    if(l>r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
}
void d_spaces(int space)
{
    for(int i=0;i<space;++i)
    {
        printf(" ");
    }
}

void display(struct t_node* root)
{
    struct node* head=new_qNode(root);
    struct node* tail=head;
    int h=(1<<height(root)-1);
    int internal;
    int x=1;
    int spaces=h/2+(h/4)*3+(h/4);
    if(spaces==1)
        spaces=3;
    while(x<=h)
    {
        d_spaces(spaces);
        internal=spaces*2-1;
        if(x==h)
            internal=3;
        int c=0;
        for(int i=0;i<x;++i)
        {
            struct t_node* temp=head->data;
            printf("%d",temp->data);
            ++c;
            if(x!=h)
                d_spaces(internal);
            else
            {
                if(c&1)
                    d_spaces(internal);
                else
                    printf(" ");
            }
            if(temp->left)
            {
                tail->next=new_qNode(temp->left);
                tail=tail->next;
            }
            if(temp->right)
            {
                tail->next=new_qNode(temp->right);
                tail=tail->next;
            }
            head=head->next;
        }
        printf("\n");
        x*=2;
        spaces/=2;
    }
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
        printf("1.In-order Traversal\n2.Pre-order Traversal\n3.Post-order traversal\n4.Display\n5.Exit\nEnter your choice: ");
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
                display(root);
                break;
            }
            case 5:
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
