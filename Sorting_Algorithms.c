// Sorting Algorithms Tracer in C By Mahmoud Atef

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void printBigO(int choice);
void intersectionSort(int arr[], int n);      // O(n^2) worst
void selectionSort(int arr[], int n);         // O(n^2) worst
void bubbleSort(int arr[], int n);            // O(n^2) worst
void quickSort(int arr[], int low, int high); // O(n^2) worst (naive pivot selection)
void mergeSort(int arr[], int l, int r);      // O(n log n) worst
void merge(int arr[], int l, int m, int r);
void shellSort(int arr[], int n); // O(n log^2 n) - O(n^4/3)

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int n;
    int *originalArr = NULL;
    int *arrCopy = NULL;

    printf("_____________________________________________\n");
    printf("__Sorting-Algorithms-Tracer-By-Mahmoud-Atef__\n");
    printf("_____________________________________________\n\n");

    while (1)
    {
        if (originalArr == NULL)
        {
            printf("Enter the number of elements (enter 0 to exit): ");
            scanf("%d", &n);

            if (n == 0)
            {
                printf("Exiting...\n");
                break;
            }

            if (originalArr != NULL)
            {
                free(originalArr);
                free(arrCopy);
            }

            originalArr = (int *)malloc(n * sizeof(int));
            arrCopy = (int *)malloc(n * sizeof(int));
            if (originalArr == NULL || arrCopy == NULL)
            {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter %d elements:-\n==> ", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &originalArr[i]);
                arrCopy[i] = originalArr[i];
            }
        }
        printf("____________________________________\n\n");
        printf("Original array: ");
        printArray(originalArr, n);

        printf("\n\nChoose a sorting algorithm:\n");
        printf("1. Intersection Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Shell Sort\n");
        printf("0. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Exiting...\n");
            // Free the dynamically allocated memory
            free(originalArr);
            free(arrCopy);
            break;
        }

        // Copy the original array to work on
        memcpy(arrCopy, originalArr, n * sizeof(int));

        switch (choice)
        {
        case 1:
            printf("Chosen algorithm: Intersection Sort\n\n");
            printBigO(choice);
            intersectionSort(arrCopy, n);
            break;
        case 2:
            printf("Chosen algorithm: Selection Sort\n\n");
            printBigO(choice);
            selectionSort(arrCopy, n);
            break;
        case 3:
            printf("Chosen algorithm: Bubble Sort\n\n");
            printBigO(choice);
            bubbleSort(arrCopy, n);
            break;
        case 4:
            printf("Chosen algorithm: Quick Sort\n\n");
            printBigO(choice);
            quickSort(arrCopy, 0, n - 1);
            break;
        case 5:
            printf("Chosen algorithm: Merge Sort\n\n");
            printBigO(choice);
            mergeSort(arrCopy, 0, n - 1);
            break;
        case 6:
            printf("Chosen algorithm: Shell Sort\n\n");
            printBigO(choice);
            shellSort(arrCopy, n);
            break;
        default:
            printf("Invalid choice!\n");
            continue;
        }

        printf("\nSorted array: ");
        printArray(arrCopy, n);
        printf("____________________________________\n");
    }

    printf("\nThanks For Using This Program! ^_^\n\n");

    return 0;
}

void printBigO(int choice)
{
    switch (choice)
    {
    case 1:
        printf("Intersection Sort Time Complexity:\n");
        printf("   - Best Case: O(n^2)\n");
        printf("   - Average Case: O(n^2)\n");
        printf("   - Worst Case: O(n^2)\n");
        printf("Intersection Sort Space Complexity:\n");
        printf("   - O(1)\n\n");
        break;
    case 2:
        printf("Selection Sort Time Complexity:\n");
        printf("   - Best Case: O(n^2)\n");
        printf("   - Average Case: O(n^2)\n");
        printf("   - Worst Case: O(n^2)\n");
        printf("Selection Sort Space Complexity:\n");
        printf("   - O(1)\n\n");
        break;
    case 3:
        printf("Bubble Sort: Time Complexity\n");
        printf("   - Best Case: O(n)\n");
        printf("   - Average Case: O(n^2)\n");
        printf("   - Worst Case: O(n^2)\n");
        printf("Bubble Sort Space Complexity:\n");
        printf("   - O(1)\n\n");
        break;
    case 4:
        printf("Quick Sort Time Complexity:\n");
        printf("   - Best Case: O(n log n)\n");
        printf("   - Average Case: O(n log n)\n");
        printf("   - Worst Case: O(n^2)\n");
        printf("Quick Sort Space Complexity:\n");
        printf("   - O(log n)\n\n");
        break;
    case 5:
        printf("Merge Sort Time Complexity:\n");
        printf("   - Best Case: O(n log n)\n");
        printf("   - Average Case: O(n log n)\n");
        printf("   - Worst Case: O(n log n)\n");
        printf("Merge Sort Space Complexity:\n");
        printf("   - O(n)\n\n");
        break;
    case 6:
        printf("Shell Sort Time Complexity:\n");
        printf("   - Best Case: O(n log^2 n)\n");
        printf("   - Average Case: O(n log^2 n)\n");
        printf("   - Worst Case: O(n^(4/3))\n");
        printf("Shell Sort Space Complexity:\n");
        printf("   - O(1)\n\n");
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    printf("\n");
}

// Intersection sort algorithm
void intersectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                printf("Swapped: %d <-> %d\n", arr[j], arr[i]);
            }
        }
    }
}

// Selection sort algorithm
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        printf("Swapped: %d <-> %d\n", arr[i], arr[min_index]);
    }
}

// Bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("Swapped: %d <-> %d\n", arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            // If no two elements were swapped, the array is already sorted
            break;
        }
    }
}

// Quick sort algorithm
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                printf("Swapped: %d <-> %d\n", arr[i], arr[j]);
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        printf("Swapped: %d <-> %d\n", arr[i + 1], arr[high]);

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge sort algorithm
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Merge function used in merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        printf("Swapped: %d <-> %d\n", arr[k], arr[k - 1]);
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Shell sort algorithm
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                printf("Swapped: %d <-> %d\n", arr[j], arr[j - gap]);
            }
            arr[j] = temp;
        }
    }
}
