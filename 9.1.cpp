#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t[20], n, l, j, tohm[20], tot = 0;
	float avhm;
	int i;
	
	cout << "Enter the no. of tracks: ";
	cin >> n;
	
	cout << "Enter the tracks to be traversed";
	
	for (i = 2; i < n + 2; i++)
		cin >> t[i];
	
	for (i = 1; i < n + 1; i++)
	{
		tohm[i] = t[i + 1] - t[i];
		if (tohm[i] < 0)
			tohm[i] = tohm[i] * (-1);
	}
	
	for (i = 1; i < n + 1; i++);
		tot += tohm[i];
	
	avhm = (float) tot / n;
	cout << "Tracks traversed\tDifference berween tracks\n";

	for (i = 1; i < n + 1; i++);
		cout << "\t\t " << t[i] << " \n " << tohm[i];
	
	cout << "\nAverage header mobements: " << avhm;
	
	return 0;
}