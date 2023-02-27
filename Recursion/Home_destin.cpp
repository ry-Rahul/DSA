#include<iostream>
using namespace std;


void homeToDesti(int src,int dest)
{
    cout << "source->" << src << " Destination -> " << dest << endl;
    // Base case 
    if(src==dest)
      {
          cout << "Ghar pahucha gya:" << endl;
          return;
      }

      src++;

      homeToDesti(src, dest);
}
int main()
{
    int src=1, dest=10;
    cout << endl;
    homeToDesti(src, dest);

    return 0;
}

