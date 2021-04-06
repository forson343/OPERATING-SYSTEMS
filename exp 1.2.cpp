#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
	int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp;
	
	cout << "\n\t\t\t------Shortest Job First(SJF)------\n";
	cout << "\nEnter the number of processes -- ";
	cin >> num_pro;
	
	for(i = 0; i < num_pro; i++)
	{
		pro[i] = i;
		cout << "Enter the burst time for process " << i << "-- ";
		cin >> burst[i];
	}
	
	for(i = 0; i < num_pro; i++)
		for(k = i + 1; k < num_pro; k++)
			if(burst[i] > burst[k])
			{
				temp = burst[i];
				burst[i] = burst[k];
				burst[k] = temp;
				
				temp = pro[i];
				pro[i] = pro[k];
				pro[k] = temp;
			}
	
	wait[0] = waitavg = 0;
	trntime[0] = trntimeavg = burst[0];
	for(i = 1; i < num_pro; i++)
	{
		wait[i] = wait[i-1] + burst[i-1];
		trntime[i] = trntime[i-1] + burst[i];
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}
	
	cout << "\n\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n";
	for (i = 0; i < num_pro; i++)
		cout << "\n\t\tP" << pro[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i];
	
	cout << "\nAverage Waiting Time --" << waitavg << endl;
	cout << "\nAverage Turnaround Time --" << trntime << endl;
	
	return 0;
}