#include <iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int main()
{
	int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp; 

	cout << "\n\t\t\t------First Come First Serve (FCFS)------\n";
	cout << "\nEnter the number of processes -- ";
	cin >> num_pro;
	
	for(i = 0; i < num_pro; i++)
	{
		cout << "\nEnter Burst Time for Process " << i << "-- ";
		cin >> burst[i];
	}
	
	wait[0] = waitavg = 0;
	trntime[0] = trntimeavg = burst[0];
	
	for(i = 1; i < num_pro; i++)
	{
		wait[i] = wait[i-1] +burst[i-1];
		trntime[i] = trntime[i-1] +burst[i];
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}
	cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";
	
	for(i = 0; i < num_pro; i++)
	cout << "\n\t P" << i << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i] << endl;
	cout << "\nAverage Waiting Time -- " << waitavg << endl;
	cout << "\nAverage Turnaround Time -- " << trntimeavg << endl;
	
	return 0;
}