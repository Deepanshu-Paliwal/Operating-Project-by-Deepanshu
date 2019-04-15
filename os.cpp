
#include<iostream> 
using namespace std;
int main() 
{ 
 
  int count,no_of_processes,i,time,remaining,flag=0,timequantum1[100],timequantum2[100], Wtime=0,TAT=0,Atime[10],Btime[10],Rtime[10]; 
  cout<<"------------------WELCOME ------------------\n";
  cout<<"Enter total no of processes "; 
  cin>>no_of_processes;
  remaining=no_of_processes; 
  for(count=0;count<no_of_processes;count++) 
  { 
    cout<<"Enter arrival time and burst time for process no. : "<<count; 
    cin>>Atime[count];
    cin>>Btime[count]; 
    Rtime[count]=Btime[count]; 
  } 
  for(i=0;i<no_of_processes;i++)
  {
  	timequantum1[i]=6;
  	timequantum2[i]=10;
  }
  cout<<"\n process|   turnaround time|       waiting time|\n"; 
  cout<<"--------------------------------------------------\n";
  for(time=0,count=0;remaining!=0;) 
  { 
    if(Rtime[count]<=timequantum1[count] && Rtime[count]>0) 
    { 
      time+=Rtime[count]; 
      Rtime[count]=0; 
      flag=1; 
    } 
    else if(Rtime[count]>0) 
    { 
      Rtime[count]=Rtime[count]-timequantum1[count]; 
      time=time+timequantum1[count]; 
    } 
    if(Rtime[count]==0 && flag==1) 
    { 
      remaining--; 
      cout<<"Process "<<count<<"       "<<time-Atime[count]<<"                          "<<time-Atime[count]-Btime[count]<<endl; 
      Wtime=Wtime+time-Atime[count]-Btime[count]; 
      TAT=TAT+time-Atime[count]; 
      flag=0; 
    } 
    if(count==no_of_processes-1) 
      count=0; 
    else if(Atime[count+1]<=time) 
      count++; 
    else 
      count=0; 
    if(Rtime[count]<Btime[count] && Rtime[count]>0)
    timequantum1[count]=timequantum2[count];
  } 
  cout<<"\nAverage Waiting Time="<<Wtime*1.0/no_of_processes; 
  cout<<"\nAvg Turnaround Time = "<<TAT*1.0/no_of_processes; 
  
  return 0; 
}

