#include <iostream>
#include<stdio.h>
#include<conio.h>
#define max 25

using namespace std;


int main() 
{
	int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
	static int bf [max], ff[max];

	cout << "\n\tMemory Management Scheme - Worst Fit";
	
	cout << "\nEnter the number of blocks:";
	cin >> nb;

	cout << "\nEnter the number of files:";
	cin >> nf;
	
	cout << "\nEnter the size of the blocks:-\n";

	for(i = 1; i <= nb; i++)
	{
		cout <<"Block " << i << ":";
		cin >> b[i];
	}

	cout <<("Enter the size of the files :-\n");

	for(i = 1;i <= nf; i++)
	{
		cout << "File " << i << ":";
		cin >> f[i];
	}
	
	for(i=1;i<=nf;i++)
	{
		for(j=1;j<=nb;j++)
		{
			if(bf[j]!=1) //if bf[j] is not allocated
			{
				temp = b[j] - f[i];
				if(temp >= 0)
					if(highest < temp)
					{
						ff[i] = j;
						highest = temp;
					}
			}
		}
		
		frag[i] = highest;
		bf[ff[i]] = 1;
		highest = 0;
	}
	
	cout << "\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement";
	
	for(i = 1; i <= nf; i++)
	
	cout << "\n\t\t \t\t \t\t \t\t " << i << f[i] << ff[i] << b[ff[i]] << frag[i];
	return 0;
}