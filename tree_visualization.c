#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

//queue functions
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
{
    //LNR
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

// Function that prints Tree using
// functions graphic.h header file
void printTree(int x, int y, struct t_node* root,int index)
{
    struct t_node* left;
    struct t_node* right;
    int lx,ry;
    char str[10];
    
    //Base case of our recursive function
    if (!root)
	    return;

    // Convert int value into string
    itoa(root->data,str,10);

    // Set color of the boundary of circle as green
    setcolor(GREEN);

    // Draw the circle of radius 15 that represent node of Tree
    circle(x, y, 15);
    delay(200);
    floodfill(x, y, GREEN);
    delay(200);

    // Print the values of the node in the circle
    outtextxy(x - 2, y - 3, str);
    delay(200);
    // Set the color of the line from parent to child as green
    setcolor(GREEN);

    // Evaluating left and right child
    left = root->left;
    right = root->right;
    lx=2*index+1;
    ry=2*index+1;

    // Recursively draw the left subtree and the right subtree
    printTree(x - y / (index + 1), y + 50,left,lx);
    printTree(x + y / (index + 1), y + 50,right,ry);

    // Draw the line (or link) when the node is not the leaf node
    if (left!=NULL)
    {
        delay(200);
        line(x, y + 14, x - y / (index + 1), y + 50 - 14);
    }
    if (right!=NULL)
    {
        delay(200);
        line(x, y + 14, x + y / (index + 1), y + 50 - 14);
    }
    return;
}
//tree function
int main()
{
    int gd = DETECT, gm,i,x,lc,rc,c=1,choice;
    struct t_node* root;
    struct t_node* temp;
    struct node* head;
    struct node* tail;
    struct node* t;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cleardevice();

    printf("NOTE: For tree input take -1 as NULL\n\n");

    printf("Enter root node data: ");
    scanf("%d",&x);
    root=new_tNode(x);
    //queue
    head=new_qNode(root);
    tail=head;//rear pointer

    while(head)
    {
        temp=head->data;

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
        t=head;
        head=head->next;
        free(t);
        printf("\n");
    }

    while(c)
    {
        printf("1. In-order Traversal\n2. Pre-order Traversal\n3. Post-order traversal\n4. Visualize Tree\n5. Exit\nEnter your choice: ");
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
                cleardevice();
                c=0;
                printTree(300, 100, root, 0);
                getch();
                cleardevice();
                break;
            }
            case 5:
            {
                c=0;
                break;
            }
            default:
            {
                printf("Invalid choice! Try again!\n");
            }
        }
        printf("\n\n");
    }
    getch();
    return 0;
}
