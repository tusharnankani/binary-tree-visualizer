#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

// graphics functions

struct points
{
  int x;
  int y;
};

void plotpixel(int x, int y)
{
	putpixel(x + 320, 240 - y, 4);
}

void dda(int x0, int y0, int x1, int y1)
{
    float dx, dy, steps, xinc, yinc;
    setbkcolor(0);
    dx = x1 - x0;
    dy = y1 - y0;

    steps = ((dx >= dy) ? dx : dy); 

    xinc = dx / steps;
    yinc = dy / steps;
    int x = x0, y = y0;

    for(int i = 1; i <= steps; ++i)
    {
        plotpixel(x, y);
        x += xinc;
        y += yinc;
    }
}
// graphics functions end;



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
//queue functions end;


//trees functions
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
    // LNR
    if(!root)
        return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder((root->right));
}

void Preorder(struct t_node* root)
{
    // NLR
    if(!root)
        return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct t_node* root)
{
    // LRN
    if(!root)
        return;
    Postorder(root->left);
    Postorder((root->right));
    printf("%d ",root->data);
}

/*
Traversing:
1.         1
2.     2       3
3.  4     5

In-Order: 4 2 5 1 3
Pre-Order: 1 2 4 5 3    
Post-Order: 4 5 2 3 1
*/
// trees functions end;


// GLOBAL DECLARATIONS;
int *a, count;
bool present[10][10];
struct points *p;

int main()
{
    printf("\nNOTE: For tree input take -1 as NULL\n\n");
    struct t_node* root = NULL;
    int x,lc,rc,count, i = 0, j, k;
    a = (int *)malloc(count * sizeof(int));
	p = (struct points *)malloc(count * sizeof(struct points));

    printf("Enter number of nodes: ");
	scanf("%d", &count);
	for(int j = 0; j < count; j++)
		for(int k = 0; k < count; k++)
			present[j][k] = 0;

    printf("\nEnter root node data: ");
    scanf("%d",&x);
    root=new_tNode(x);
    a[i] = x;
    p[i].x = 0;
    p[i].y = 100;
    j = i;
    i += 1;

    //queue
    struct node* head=new_qNode(root);
    struct node* tail=head;//rear pointer
    while(head)
    {
        struct t_node* temp=head->data;
        int curr_xco = p[j].x, curr_yco = p[j].y;

        printf("\nEnter left child of %d: ",temp->data);
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

            a[i] = lc;
            p[i].x = curr_xco - 50;
            p[i].y = curr_yco - 50;
            k = i;
            present[j][k] = 1;
            i += 1;
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

            a[i] = rc;
            p[i].x = curr_xco - 50;
            p[i].y = curr_yco - 50;
            k = i;
            present[j][k] = 1;
            i += 1;
        }
        struct node* t=head;
        head=head->next;
        free(t);

        j += 1;
    }
    int c=1,choice;
    while(c)
    {
        printf("0. Visualize Tree \n1.In-order Traversal\n2.Pre-order Traversal\n3.Post-order traversal\n4.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: 
            {
                clrscr();
                printf("Creating tree....");
                delay(2000); 
                c = 0;
                break;
            }
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
                c = 0;
                break;
            }
            default:
            {
                printf("Invalid choice! Please Try again! \n");
            }
        }
        printf("\n");
    }

    // MAIN Graphics code.
    int gd = DETECT, gm, i, m, n;
	int *s, x1, y1, x2, y2;
	char snum[5];
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    cleardevice();
	s =(int *)malloc(count * sizeof(int));
	for(i = 0; i < count; i++)
	{
		itoa(a[i], snum, 10);
		outtextxy(p[i].x + 320, 240 - p[i].y, snum);
		s[i] = 0;
	}
	for(m = 0; m < count; m++)
	{
		for(n = 0; n < count; n++)
		{
			if(present[m][n])
			{
				x1 = p[m].x;
				y1 = p[m].y;
				x2 = p[n].x;
				y2 = p[n].y;
				dda(x1, y1, x2, y2);
			}
		}
	}
	getch();
	closegraph();

    return 0;
}
