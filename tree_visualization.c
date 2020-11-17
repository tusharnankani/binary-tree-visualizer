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
    // Set color of the boundary of
    // circle as green
    setcolor(GREEN);
    // Draw the circle of radius 15
    // that represent node of Tree
    circle(x, y, 15);
    delay(100);
    floodfill(x, y, GREEN);
    delay(100);
    // Print the values of the node
    // in the circle
    outtextxy(x - 2, y - 3, str);
    delay(100);
    // Set the color of the line
    // from parent to child as green
    setcolor(GREEN);
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
	delay(100);
	line(x, y, x - y / (index + 1), y + 50);
    }
    if (right < total_elements)
    {
	delay(100);
	line(x, y, x + y / (index + 1), y + 50);
    }
    return ;
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
    printTree(300, 100, array, 0, size);
    getch();
    closegraph();
    return 0;
}
