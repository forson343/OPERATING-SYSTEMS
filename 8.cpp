#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;


	struct file
	{
		int all[10];
		int max[10];
		int need[10];
		int flag;
	};
	
	int main()
	{
		struct file f[10];
		int fl, i, j, k , p, b, n, r, g, cnt = 0, id, newr;
		int avail[10], seq[10];
		
		cout << "Enter the number of processes ---- ";
		cin >> n;
		
		cout << "Enter the number of resources ---- ";
		cin >> r;
		
		for (i = 0; i < n; i++)
		{
			cout << "Enter details for P" << i << " -- " << endl;
			cout << "Enter allocation\t-- \t";
				for (j = 0; j < r; j++)
					cin >> f[i].max[j];
				
				cout << "Enter Max\t\t-- \t";
				for (j = 0; j < r; j++)
					cin >> f[i].max[j];
				f[i].flag = 0;
		}
		
		cout  << "\nEnter available resources\t-- \t";
		for (i = 0; i < n; i++)
			cin >> avail[i];
		
		cout << "\nEnter New Request Details -- " << endl;
		cout << "\nEnter pid\t-- \t";
		cin >> id;
		
		cout << "Enter Request for Resources \t-- \t";
		for (i = 0; i < r; i++)
		{
			cin >> newr;
			f[id].all[i] += newr;
			avail[i] = avail[i] - newr;
		}
		
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < r; j++)
			{
				f[i].need[j] = f[i].max[j] - f[i].all[i];
				if (f[i].need[j] < 0)
					f[i].need[j] = 0;
			}
		}
		
		cnt = 0;
		fl = 0;
		
		while (cnt != n)
		{
			g = 0;
			
			for (i = 0; i < n; i++)
			{
				if (f[j].flag == 0)
				{
					b = 0;
					for (p = 0; p < r; p++)
					{
						if (avail[p] >= f[j].need[p])
							b = b + 1;
							
						else
							b = b - 1;
					}
					
					if (b == r)
					{
						cout << "\nP " << j << " is visited";
						seq[fl++] = j;
						f[j].flag = 1;
						
						for(k = 0; k < r; k++)
							avail[k] = avail[k] + f[j].all[k];
						
						cnt = cnt + 1;
						cout << "(";
						
						for(k = 0; k < r; k++)
							cout << avail[k];
						cout << ")";
						
						g = 1;
					}
				}
			}
			
			if (g == 0)
			{
				cout << "\nREQUEST NOT GRANTED -- DEADLOCK OCCURED";
				cout << "\nSYSTEM IS IN UNSAFE STATE";
				
				goto y;
			}
		}
		
		cout << "SYSTEM IS IN SAFE STATE";
		cout << "The Safe Sequence is -- (";
		
		for (i = 0; i < fl; i++)
			cout << "P " << seq[i];
		cout << ")";
		
		y: cout << "\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n";
		for (i = 0; i < n; i++)
		{
			cout << "P " << i << "\t";
			for (j = 0; j < r; j++)
				cout << f[i].all[j];
			
			for (j = 0; j < r; j++)
				cout << f[i].max[j];
			
			for (j = 0; j < r; j++)
				cout << f[i].need[j];
				
			cout << "\n";
		}
		return 0;
	} 










