mergesort(int a[],int b[], int m, int n,int i,int j)
{
    while(i<=m && j<=n)
    {
        if(a[i]<=b[j])
        {
            c[k]=a[i];
            i++;

        }
        else{
            c[k]=b[j];
            j++;
        }
          k++;

    }
     if(m>i)
}