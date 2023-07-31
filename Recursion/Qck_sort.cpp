#include <iostream> // QUICK SORT insertion sort me ham
                    // jaise jaise aage badhte jayenge array sort hota jayega
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
void show(int a[])
{
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;
}
int quick(int a[], int left, int right)
{
    int i, loc, t;
    loc = left;
    while (left < right)
    {
        while (left < right && a[loc] <= a[right])
            right--;
        if (left == right)
            break;
        else
        {  
            swap(a[loc], a[right]);
            loc = right;
        }

        while (left < right && a[loc] >= a[left])
            left++;
        if (left == right)
            break;
        else
        {
            swap(a[loc], a[left]);
            loc = left;
        }
    }
    return loc;
}
void Quick_sort(int a[], int l, int u)
{
    int loc, i, t;
    loc = quick(a, l, u);
    if (l + 1 < loc) // base case
        Quick_sort(a, l, loc - 1);
    if (u - 1 > loc) // base case
        Quick_sort(a, loc + 1, u);
}
int minvalueindex(int a[], int i, int n)
{
    int min, minindex;
    min = a[i];
    for (i; i <= n - 1; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            minindex = i;
        }
    }
    return minindex;
}
void selection_sort(int a[], int n)
{
    int i, t, minindex;
    for (i = 0; i <= n - 2; i++)
    {
        minindex = minvalueindex(a, i, n);
        
        if (a[i] > a[minindex])
        {
            t = a[i];
            a[i] = a[minindex];
            a[minindex] = t;
        }
    }
}

int main()
{
    // system("color a");
    // int i,j,k;
    int a[] = {99, 53, 61, 74, 12, 31, 59, 82, 41, 7};
    cout << "<<-----Quick sort----->>" << endl;
    cout << endl;
    show(a);
    Quick_sort(a, 0, 9);
    cout << endl;
    show(a);
    // getch();
}