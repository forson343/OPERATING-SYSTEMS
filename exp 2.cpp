#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
	int pro[20], burst[20], su[20], wait[20], trntime[20],i, k, num_pro, temp;
	float waitavg, trntimeavg;
	
	cout << "Enter the number of processes --- ";
	cin >> num_pro;
	
	for(i = 0; i < num_pro; i++)
	{
		pro[i] = i;
		cout << "Enter the burst time for process " << i << " -- ";
		cin >> burst[i];
		
		cout << "System/User Process (0/1)? --- ";
		cin >> su[i];
	}
	
	for(i = 0; i < num_pro; i++)
		for(k = i + 1; k < num_pro; k++)
			if(su[i] > su[k])
			{
				temp = pro[i];
				pro[i] = pro[k];
				pro[k] = temp;
				
				temp = burst[i];
				burst[i] = burst[k];
				burst[k] = temp;
				
				temp = su[i];
				su[i] = su[k];
				su[k] = temp;
			}
			
	waitavg = wait[0] = 0;
	trntimeavg = trntime[0] = burst[0];
	
	for(i = 1; i < num_pro; i++)
	{
		wait[i] = wait[i-1] + burst[i-1];
		trntime[i] = trntime[i-1] + burst[i];
	
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}
	
	cout << "\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME";
	for (i = 0; i < num_pro; i++)
		cout << "\nP" << pro[i] << "\t\t\t" << su[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i];
	
	cout << "\nAverage Waiting Time -- " << waitavg << endl;
	cout << "\nAverage Turnaround Time -- " << trntime << endl;

	return 0;	
}