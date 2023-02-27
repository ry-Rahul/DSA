#include <iostream>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val);
    void print();
    void deletion();
    // void heapify(int arr[], int n, int i);
    // void heapSort(int arr[], int size);

};

void heap::insert(int val)
{
    size = size + 1;
    int index = size;

    while (index > 1)
    {
        int parent = index / 2;

        if (val <= arr[parent])
        {
            break;
        }
        arr[index] = arr[parent];
        index = parent;
    }
    arr[index] = val;
}

void heapify(int arr[], int n, int i )
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

      if(left<=n && arr[largest ]< arr[left])
          largest = left;

      if(right<=n && arr[largest]<arr[right])
          largest = right;
          
      if(largest != i)
      {
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // Step1 swap
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

void heap::deletion()
{ // Olog(n)
    if (size == 0)
    {
        cout << "Nothing to delete " << endl;
        return;
    }
    else
    {
        // step1: put last element into first index
        arr[1] = arr[size];
        // int last =arr[size];
        size--;
        // taking root node to its correct position
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
}
void heap::print()
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr[6] = {0, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Heapified array is: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr,n);
    cout << "Heap Sort Arrey is: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}