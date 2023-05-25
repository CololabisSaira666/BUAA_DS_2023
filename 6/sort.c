#include <stdio.h>

int num[100];
int B[100];

void swap(int* a, int* b);
void selectionSort(int n);
void bubbleSort(int n);
void heapSort(int n);
void twowayMergeSort(int n);
int mergeSort(int count, int low, int high);
int merge(int count, int low, int mid, int high);
int quickSort(int count, int left, int right);

int main()
{
    int n, op, i, count = 0;
    scanf("%d %d", &n, &op);
    for ( i = 0; i < n; i++)
        scanf("%d", &num[i]);
    
    if(op == 1)
        selectionSort(n);
    else if(op == 2)
        bubbleSort(n);
    else if(op == 3)    
        heapSort(n);
    else if(op == 4)
        twowayMergeSort(n);
    else if(op == 5)
    {
        count = quickSort(count, 0, n-1);
        for(i = 0; i < n; i++)
            printf("%d ", num[i]);
        printf("\n");
        printf("%d", count);
    }
    return 0;
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selectionSort(int n)
{
    int count = 0;
    int i, j;
    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            count++;
            if(num[i] > num[j])
                swap(&num[i], &num[j]);
        }
    }
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
    printf("%d", count);
}

void bubbleSort(int n)
{
    int i, j, flag = 0;
    int count = 0;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1-i; j++)
        {
            count++;
            if(num[j] > num[j+1])
            {
                swap(&num[j], &num[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
        flag = 0;
    }
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
    printf("%d", count);
}

void heapSort(int n) // 堆排序
{
    int i, count = 0;
    int dad, son;
    for(i = n/2-1; i >= 0; i--)
    {
        dad = i;
        son = dad *2 + 1;
        while (son <= n-1)
        {
            if(son+1 <= n-1 && num[son] < num[son+1])
                son++;
            count++;
            if(num[dad] > num[son])
                break;
            else
            {
                swap(&num[dad], &num[son]);
                dad = son;
                son = dad *2 + 1;
            }
        }
    }
    for ( i = n-1; i > 0; i--)
    {
        swap(&num[0], &num[i]);
        dad = 0;
        son = dad *2 + 1;
        while (son <= i-1)
        {
            if(son+1 <= i-1 && num[son] < num[son+1])
                son++;
            count++;
            if(num[dad] > num[son])
                break;
            else
            {
                swap(&num[dad], &num[son]);
                dad = son;
                son = dad *2 + 1;
            }
        }
    }
    
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
    printf("%d", count);
}

void twowayMergeSort(int n)
{
    int i, count = 0;
    count = mergeSort(count, 0, n-1);
    for(i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
    printf("%d", count);
}

int mergeSort(int count, int low, int high) //划分函数
{
    if(low < high) 
    {
        int mid = (low + high)/2;
        count = mergeSort(count, low, mid);
        count = mergeSort(count, mid+1, high);
        count = merge(count, low, mid, high);
    }
    return count;
}

int merge(int count, int low, int mid, int high)
{
    int i, j, k;
    for ( k = low; k < high+1; k++)
    {
        B[k] = num[k];
    }
    i = low;
    j = mid + 1;
    k = low;
    while (i < mid+1 && j < high+1)
    {
        count++;
        if(B[i] > B[j])
            num[k++] = B[j++];
        else
            num[k++] = B[i++];
    }
    while (i < mid+1)
        num[k++] = B[i++];
    while (j < high+1)
        num[k++] = B[j++];
    
    return count;
}

int quickSort(int count, int left, int right)
{
    int i, last;
    if(left < right)
    {
        last = left;
        for(i = left+1; i <= right; i++)
        {
            count++;
            if (num[i] < num[left])
                swap(&num[++last], &num[i]);
        }
        swap(&num[left], &num[last]);
        count = quickSort(count, left, last-1);
        count = quickSort(count, last+1, right);
    }
    return count;
}