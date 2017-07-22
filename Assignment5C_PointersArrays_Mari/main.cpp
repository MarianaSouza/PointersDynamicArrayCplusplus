#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

struct myArray {
	int *ArrayAddr;
	int ArraySize;
};

myArray MyArray;

void main()
{
	int Choice; //declarations 
	void Alocate(); //function declaration
	void Initialize();
	void Max();
	void Min();
	void Avg();
	void Sort();

	Choice = 0; //initializing the variable


	printf("************** MAIN MENU ****************\n");
	printf("Please Enter one of the following Choices\n");
	printf("************** MAIN MENU ****************\n\n");

	do
	{
		printf("1: Allocating space for the array.\n");
		printf("2: Initialize the array.\n");
		printf("3: Find the max element of the array.\n");
		printf("4: Find the minimum element of the array.\n");
		printf("5: Find the average of the array elements.\n");
		printf("6: Sort the array.\n");
		printf("7: Exit the program.\n");
		scanf_s("%d", &Choice);

		switch (Choice)
		{
		case 1:
			Alocate();
			break;
		case 2:
			Initialize();
			break;
		case 3:
			Max();
			break;
		case 4:
			Min();
			break;
		case 5:
			Avg();
			break;
		case 6:
			Sort();
			break;
		default:
			break;
		}

	} while (Choice != 7); //when the choice is == 7, the program ends (return)
}

void Alocate()
{
	printf("%s", "What is the array size? ");
	scanf("%d", &MyArray.ArraySize);
	MyArray.ArrayAddr = (int *)malloc(sizeof(int)* MyArray.ArraySize);

	
}
void Initialize()
{
	int * currentElement = MyArray.ArrayAddr;
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		printf("Give me the value of each element of the array: ");
		scanf("%d", currentElement);
		currentElement++;
		
	}
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		printf("\nArrayElement[%d] = %d ", i, MyArray.ArrayAddr[i]);
		printf("\n\n");
	}
}
void Max()
{
	int max = 0;
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		if (MyArray.ArrayAddr[i] > max)
		{
			max = MyArray.ArrayAddr[i];
		}
	}
	printf("The MAX number in the array is: ");
	printf("%d\n\n", max);
}
void Min()
{
	int min = 0;
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		if ( min == 0)
		{
			min = MyArray.ArrayAddr[i];
		}
		
		if (MyArray.ArrayAddr[i] < min)
		{
			min = MyArray.ArrayAddr[i];
		}
	}
	printf("The MIN number in the array is: ");
	printf("%d\n\n", min);
}
void Avg()
{
	int sum = 0;
	float average = 0;
	for (int i = 0; i < MyArray.ArraySize; i++)
	{

			sum += MyArray.ArrayAddr[i];
	}
	average = sum / MyArray.ArraySize;
	printf("The array AVERAGE is: ");
	printf("%.1f\n\n", average);
}
void Sort()
{
	int temp = 0;
	//Ascending
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		for (int j = 0; j < (MyArray.ArraySize - i - 1); j++)
		{
			if (MyArray.ArrayAddr[j] >  MyArray.ArrayAddr[j + 1])
			{
				temp = MyArray.ArrayAddr[j];
				MyArray.ArrayAddr[j] = MyArray.ArrayAddr[j + 1];
				MyArray.ArrayAddr[j + 1] = temp;
			}
		}
	}
	printf("Sorted array in ascending order is...\n");
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		printf("%d\n\n", MyArray.ArrayAddr[i]);
	}


	//Descending
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		for (int j = i + 1; j < MyArray.ArraySize; j++)
		{
			if (MyArray.ArrayAddr[i] <  MyArray.ArrayAddr[j])
			{
				temp = MyArray.ArrayAddr[i];
				MyArray.ArrayAddr[i] = MyArray.ArrayAddr[j];
				MyArray.ArrayAddr[j] = temp;
			}
		}
	}
	printf("Sorted array in descending order is...\n");
	for (int i = 0; i < MyArray.ArraySize; i++)
	{
		printf("%d\n\n", MyArray.ArrayAddr[i]);
	}

}


