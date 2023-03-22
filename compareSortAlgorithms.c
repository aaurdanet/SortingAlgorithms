#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int extraMemoryAllocated;

// implement merge sort
// extraMemoryAllocated counts bytes of extra memory allocated
void mergeSort(int pData[], int l, int r)
{

    if (l >= r) return;

    int mid = l + (r - l) / 2;
    mergeSort(pData, l, mid);
    mergeSort(pData, mid + 1, r);

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = pData[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = pData[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            pData[k++] = L[i++];
        else
            pData[k++] = R[j++];
    }

    while (i < n1) pData[k++] = L[i++];
    while (j < n2) pData[k++] = R[j++];
}

// implement insertion sort
// extraMemoryAllocated counts bytes of memory allocated
void insertionSort(int* pData, int n)
{
	int i, key, j;
	extraMemoryAllocated = 0;
	for (int i = 1; i < n; i++)
	{
		key = pData[i];
		j = i - 1;

		while (j >= 0 && pData[j] > key) {
			pData[j + 1] = pData[j];
			j = j - 1;
			extraMemoryAllocated += sizeof(int);
		}
		pData[j + 1] = key;
	}
}

// implement bubble sort
// extraMemoryAllocated counts bytes of extra memory allocated
void bubbleSort(int* pData, int n)
{
	int y, temp, x;
	extraMemoryAllocated = 0;
	for (int x = 0; x < n - 1; x++) {

		for (y = 0; y < n - x - 1; y++) {

			if (pData[y] > pData[y + 1]) {

				temp = pData[y];

				pData[y] = pData[y + 1];

				pData[y + 1] = temp;

			}

		}

	}
}

// implement selection sort
// extraMemoryAllocated counts bytes of extra memory allocated
void selectionSort(int* pData, int n)
{
	int min_index;
	extraMemoryAllocated = 0;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (pData[min_index] > pData[j]) {
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = pData[i];
			pData[i] = pData[min_index];
			pData[min_index] = temp;
		}

	}
}

// parses input file to an integer array


int parseData(char* inputFileName, int** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	if (!inFile) {
		return 0;
	}

	int dataSz = 0;
	fscanf(inFile, "%d\n", &dataSz);

	*ppData = malloc(sizeof(int) * dataSz);

	if (!*ppData) {
		fclose(inFile);
		return 0;
	}

	for (int i = 0; i < dataSz; i++)
	{
		if (fscanf(inFile, "%d", (*ppData) + i) != 1)
		{
			fclose(inFile);
			free(*ppData);
			*ppData = NULL;
			return 0;
		}
	}

	fclose(inFile);
	return dataSz;
}

// prints first and last 100 items in the data array
void printArray(int pData[], int dataSz)
{
	int i, sz = dataSz - 100;
	printf("\tData:\n\t");
	for (i = 0; i < 100; ++i)
	{
		printf("%d ", pData[i]);
	}
	printf("\n\t");

	for (i = sz; i < dataSz; ++i)
	{
		printf("%d ", pData[i]);
	}
	printf("\n\n");
}

int main(void)
{
	clock_t start, end;
	int i;
	double cpu_time_used;
	char* fileNames[] = { "input1.txt", "input2.txt", "input3.txt" };

	for (i = 0; i < 3; ++i)
	{
		int* pDataSrc, * pDataCopy;
		int dataSz = parseData(fileNames[i], &pDataSrc);

		if (dataSz <= 0)
			continue;

		pDataCopy = (int*)malloc(sizeof(int) * dataSz);

		printf("---------------------------\n");
		printf("Dataset Size : %d\n", dataSz);
		printf("---------------------------\n");

		printf("Selection Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz * sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		selectionSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n", cpu_time_used);
		printf("\textra memory allocated\t: %d\n", extraMemoryAllocated);
		printArray(pDataCopy, dataSz);

		printf("Insertion Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz * sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		insertionSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n", cpu_time_used);
		printf("\textra memory allocated\t: %d\n", extraMemoryAllocated);
		printArray(pDataCopy, dataSz);

		printf("Bubble Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz * sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		bubbleSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n", cpu_time_used);
		printf("\textra memory allocated\t: %d\n", extraMemoryAllocated);
		printArray(pDataCopy, dataSz);

		printf("Merge Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz * sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		mergeSort(pDataCopy, 0, dataSz - 1);
		end = clock();
		cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n", cpu_time_used);
		printf("\textra memory allocated\t: %d\n", extraMemoryAllocated);
		printArray(pDataCopy, dataSz);

		free(pDataCopy);
		free(pDataSrc);
	}

}