#include <iostream>
#include <stdlib.h>

using namespace std;

//1. Create an Array
int *createArray();
//2. Insert elements in array
void insertArray(int *, int size);
//3. Insert at start in array
void insertAtStart(int *);
//4. Insert at end in array
void insertAtEnd(int *, int size);
//5. Insert at given position in array
void insertAtPos(int *, int size);
//6. Travese print through array
void printArray(int *, int size);
//7. Search in an array
void searchLinear(int *, int size);
//8. Delete from start in array
void deleteAtStart(int *, int size);
//9. Delete from end in array
void deleteAtEnd(int *, int size);
//10.Delete at given pos in array
void deleteAtPos(int *, int size);
//11. Covert to Sparce Matrix
void sparceMatrix();
//12. Add and MUL
void matrixOperation();

// var decralations
int *arr = NULL;
int arraySize = 0;

/*
*****************Main Driver*****************
*/
int main(int argc, char *argv[])
{
	int option = 0;
	while (option != 13)
	{
		cout << "\n******************\nChoose an option:\n---------------\n 1. Create an Array\n 2. Insert elements in array\n 3. Insert at start in array\n 4. Insert at end in array\n 5. Insert at given position in array\n 6. Travese print through array\n 7. Search in an array\n 8. Delete from start in array\n 9. Delete from end in array\n 10.Delete at given pos in array \n 11.Convert to Sparce Matrix \n12. ADD & MUL Matrix \n13. EXIT\n******************\n";
		cin >> option;
		switch (option)
		{
		case 1:
			//1. Initilaize an array
			arr = createArray();
			break;
		case 2:
			//2. Insert elements in array
			insertArray(arr, arraySize);
			break;
		case 3:
			//3. Insert at start in array
			insertAtStart(arr);
			break;
		case 4:
			//4. Insert at end in array
			insertAtEnd(arr, arraySize);
			break;
		case 5:
			//5. Insert at given position in array
			insertAtPos(arr, arraySize);
			break;
		case 6:
			//6. Travese print through array
			printArray(arr, arraySize);
			break;
		case 7:
			//7.Search in an array
			searchLinear(arr, arraySize);
			break;
		case 8:
			//8. Delete from start in array
			deleteAtStart(arr, arraySize);
			break;
		case 9:
			//9. Delete from end in array
			deleteAtEnd(arr, arraySize);
			break;
		case 10:
			//10. Delete at given pos in array
			deleteAtPos(arr, arraySize);
			break;
		case 11:
			//11. Convert to sparce matrix
			sparceMatrix();
			break;
		case 12:
			//12. Add and Multiply matrix
			matrixOperation();
			break;
		case 13:
			//exit
			return 0;
			break;
		default:
			cout << "Choose from given option";
			break;
		}
	}
}

/*
*****************Functions*****************
*/
//1. Create an Array
int *createArray()
{
	if (arraySize > 0)
	{
		cout << "Old Array will be removed !";
		free(arr);
	}
	cout << "\nEnter size of array to create.\n";
	cin >> arraySize;
	int *arr;
	arr = (int *)malloc(arraySize * sizeof(int));
	cout << "\n\nArray of size " << arraySize << " created" << endl;
	return arr;
}

//2. Insert elements in array
void insertArray(int *array, int size)
{
	if (arr != NULL)
	{
		cout << "Old Array will be overwritten !\n";
		for (int i = 0; i < size; i++)
		{
			cout << "Enter number for index " << i << endl;
			cin >> arr[i];
		}
		printArray(arr, size);
	}
	else
	{
		cout << "Cannot Insert, Array is not initialized!";
	}
	return;
}

//3. Insert at start in array
void insertAtStart(int *)
{
	if (arr != NULL)
	{
		cout << "\n Enter item to insert : ";
		int item = 0;
		cin >> item;
		arr[0] = item;
		printArray(arr, arraySize);
	}
	else
	{
		cout << "Cannot Insert, Array is not initialized!";
	}
	return;
}
//4. Insert at end in array
void insertAtEnd(int *, int size)
{
	if (arr != NULL)
	{
		cout << "\n Enter item to insert : ";
		int item = 0;
		cin >> item;
		arr[size - 1] = item;
		printArray(arr, size);
	}
	else
	{
		cout << "Cannot Insert, Array is not initialized!";
	}
	return;
}

//5. Insert at given position in array
void insertAtPos(int *, int size)
{
	if (arr != NULL)
	{
		cout << "\n Enter position to insert at : ";
		int pos = 0;
		cin >> pos;
		if (pos < 1 || pos > size)
		{
			cout << "Max Position is " << size;
		}
		else
		{
			cout << "Enter item to insert : ";
			int item = 0;
			cin >> item;
			arr[pos - 1] = item;
		}
		printArray(arr, size);
	}
	else
	{
		cout << "Cannot Insert, Array is not initialized!";
	}
	return;
}

//6. Travese print through array
void printArray(int *arr, int size)
{
	if (size < 1)
	{
		cout << "No element to print in Array";
		return;
	}
	cout << " \n The array is : \n ";
	for (int i = 0; i < size; i++)
	{
		cout << "(" << i + 1 << ") ";
		cout << arr[i] << "     ";
	}
	cout << "\n";
}

//7. Search in an array
void searchLinear(int *, int size)
{
	int item;
	cout << "\nEnter Element To search :\n";
	cin >> item;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == item)
		{
			cout << item << " found at pos " << i + 1;
			return;
		}
	}
	cout << item << "not found in list";
}

//8. Delete from start in array
void deleteAtStart(int *, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arraySize--;
	printArray(arr, arraySize);
}

//9. Delete from end in array
void deleteAtEnd(int *, int size)
{
	arraySize--;
	printArray(arr, arraySize);
}

//10. Delete at given pos in array
void deleteAtPos(int *, int size)
{
	int pos;
	cout << "\nEnter position to delete \n";
	cin >> pos;
	if (pos < 0 || pos > size)
	{
		cout << "\nEnter a valid position \n";
		return;
	}
	for (int j = pos; j < size; j++)
	{
		arr[j] = arr[j + 1];
	}
	arraySize--;
	printArray(arr, arraySize);
}

//11. Convert to Sparce Matrix
void sparceMatrix()
{
	int iRows = 3, iColumns = 3;
	cout << "Enter number of rows ";
	cin >> iRows;
	cout << "Enter number of Columns ";
	cin >> iColumns;
	if (iRows < 1 || iColumns < 1)
	{
		cout << "Enter valid rows ands columns\n";
		return;
	}
	cout << "\nEnter a  Matrix to convert :" << iRows << " X " << iColumns << "\n";
	int iMatrix[iRows][iColumns];

	for (int i = 0; i < iRows; i++)
		for (int j = 0; j < iColumns; j++)
			cin >> iMatrix[i][j];

	int count = 0;
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iColumns; j++)
		{
			if (iMatrix[i][j] != 0)
				count++;
		}
	}
	cout << count << endl;
	int sparceMatrix[3][count];
	int k = 0;
	for (int i = 0; i < iRows; i++)
	{
		for (int j = 0; j < iColumns; j++)
		{
			if (iMatrix[i][j] != 0)
			{
				sparceMatrix[0][k] = i;
				sparceMatrix[1][k] = j;
				sparceMatrix[2][k] = iMatrix[i][j];
				k++;
			}
		}
	}

	cout << "\nThe sparce matrix is: \n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout << sparceMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

//12. Matrix Multiplication
void matrixOperation()
{
	int matA[2][2];
	int matB[2][2];
	cout << "\nEnter 2 X 2 Matrix A \n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> matA[i][j];
		}
	}

	cout << "\nEnter 2 X 2 Matrix B\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> matB[i][j];
		}
	}

	int matAdd[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			matAdd[i][j] = matA[i][j] + matB[i][j];
		}
	}

	cout << "\nThe Add matrix is: \n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matAdd[i][j] << " ";
		}
		cout << endl;
	}

	int matMul[2][2];
	int i, j, k;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			matMul[i][j] = 0;
			for (k = 0; k < 2; k++)
				matMul[i][j] += matA[i][k] * matB[k][j];
		}
	}

	cout << "\nThe Multiply matrix is: \n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matMul[i][j] << " ";
		}
		cout << endl;
	}
}