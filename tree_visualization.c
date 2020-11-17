#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

// Function that prints Tree using
// functions graphic.h header file
void printTree(int x, int y, int* array,int index,int total_elements)
{
    int left,right;
    char str[10];
    //Base case of our recursive function
    if (index >= total_elements)
	    return;

    // Convert int value into string
    itoa(array[index],str,10);

    // Set color of the boundary of circle
    setcolor(BLACK);

    // Draw the circle of radius 15 that represent node of Tree
    circle(x, y, 15);
    delay(200);
    floodfill(x, y, RED);
    delay(200);

    // Print the values of the node
    // in the circle
    outtextxy(x - 2, y - 3, str);
    delay(200);
    // Set the color of the line
    setcolor(RED);
    // Evaluating left and right child
    left = 2 * index + 1;
    right = 2 * index + 2;
    // Recursively draw the left subtree
    // and the right subtree
    printTree(x - y / (index + 1), y + 50,array, left, total_elements);
    printTree(x + y / (index + 1), y + 50,array, right, total_elements);
    
    // Draw the line (or link) when the
    // node is not the leaf node
    if (left < total_elements)
    {
        delay(200);
	    line(x, y + 14, x - y / (index + 1), y + 50 - 14);
    }
    if (right < total_elements)
    {
        delay(200);
        line(x, y + 14, x + y / (index + 1), y + 50 - 14);
    }
}

int main()
{
    int gd = DETECT, gm,size=0,i;
    int *array;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    printf("Enter the number of nodes:  ");
    scanf("%d",&size);
    array=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;++i)
    {
        printf("Enter node %d: ",i+1);
        scanf("%d",(array+i));
    }
    clrscr();
    setbkcolor(BLACK);
    printTree(300, 100, array, 0, size);
    getch();
    closegraph();
    return 0;
}
