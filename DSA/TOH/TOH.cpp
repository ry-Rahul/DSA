#include <bits/stdc++.h> // TOH program
using namespace std;

void TOH(int n, char beg, char aux, char end)
{
	if (n > 0)
	{
		TOH(n - 1, beg, end, aux);
		cout << "\n"
			 << beg << "->" << end;
		TOH(n - 1, aux, beg, end);
	}
}
int main()
{

	int n;
	cout << "Enter no of rings for steps:" << endl;
	cin >> n;
	char A, B, C;
	TOH(n, 'A', 'B', 'C');
	return 0;
}