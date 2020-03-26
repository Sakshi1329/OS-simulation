//Header files
#include<stdio.h>
#include<conio.h> 

//main function
int main()
{   

//variables declaration
    int bt[20],at[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    float avg_wtt, avg_tatt;
    
//total number of process
	printf("Enter Total Number of Process:");
    scanf("%d",&n);
    
//entering arrival time and calculation of burst time 
    for(i=0;i<n;i++)
    {
        printf("\n P[%d]\n",i+1);
        printf("Arrival time:");
        scanf("%d",&at[i]);
        bt[i]=2*at[i];
        printf("Burst time:%d\n",bt[i]);
        p[i]=i+1;           
    }
 
//sorting the burst time 
    for(i=0;i<n;i++)
    {
     for(j=i+1;j<n;j++)
        {
         if(bt[i]<bt[j])
           {
	        temp=at[j];
            at[j]=at[i];
            at[i]=temp;
        
            temp=bt[j];
            bt[j]=bt[i];
            bt[i]=temp;
 
            temp=p[j];
            p[j]=p[i];
            p[i]=temp;
           }
        }
    }
    
//inital process waiting time is zero
	wt[0]=0;	
    
//calculation of waiting time for rest of the processes
	for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
    }
    
//calculating average waiting time for the proceses
    avg_wt=total/n;      
    
	total=0;
 
//to display the output in tabular form
    printf("*************************************************************************************************");
    printf("\n\t\t\t\t\t\t\t RESULT:-");
    printf("\n\t\t\t\t\t  Non-Preemptive\n\n");
    printf("\n\t\t------------------------------------------------------------------------------------");
    printf("\n\t\t|PROCESS|   \tAT\t|   \tBT\t|   \tWT\t|   \tTAT\t|" );
    printf("\n\t\t------------------------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
//calcuation of turnaround time of process
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\n\t\t|p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t| ",p[i],at[i],bt[i],wt[i],tat[i]); //for output in tabular form
    }
    printf("\n\t\t------------------------------------------------------------------------------------");
    
//calcution of average turnaround time for the processes
    avg_tat=total/n;     

//Gantt chart	
	printf("\n\t\t\t\t ..Order of execution according to Gantt chart..\n\n");
    printf("\t\t\t\t\t--------------\n\t\t\t\t\t");
    for(i=0;i<n;i++)
    {
     printf("| Process[%d] |\n\t\t\t\t\t",p[i]);
    }   
//printing the output of average waiting and turnaround time
	printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n\n\n\n\n",avg_tat);
 
//using short job first scheduling 
//sorting the burst time   
   for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }
   

//inital value of waiting time of first process   
    wt[0]=0;           
  
//calculation of waiting time of rest of the processes  
    for(i=1;i<n;i++)
    {
      wt[i]=0;
      for(j=0;j<i;j++)
        wt[i]+=bt[j];
      total+=wt[i];
    }

//calculation of average waiting time for the proceses 
   avg_wtt=(float)total/n;      
   total=0;

//tabular form of the result
   printf("*********************************************************************************************");
   printf("\n\t\t\t\t\t\t\t RESULT:-");
   printf("\n\t\t\t\t\t Short Job First,  Non-Preemptive\n\n");
   printf("\n\t\t------------------------------------------------------------------------------------");
   printf("\n\t\t|PROCESS|   \tAT\t|   \tBT\t|   \tWT\t|   \tTAT\t|" );
   printf("\n\t\t------------------------------------------------------------------------------------");
   for(i=0;i<n;i++)
    {
//calcuation of turnaround time of process
     tat[i]=bt[i]+wt[i];     
     total+=tat[i];
	 printf("\n\t\t|p[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t| ",p[i],at[i],bt[i],wt[i],tat[i]); //output form
    }
    printf("\n\t\t------------------------------------------------------------------------------------");
//calcution of average turnaround time for the processes 
    avg_tatt=(float)total/n;     
//Gantt cart    
    printf("\n\t\t\t\t ..Order of execution according to Gantt chart..\n");
    printf("\t\t\t\t\t--------------\n\t\t\t\t\t");
    for(i=0;i<n;i++)
    {
      printf("| Process[%d] |\n\t\t\t\t\t",p[i]);
    }
//Output for average waiting and turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wtt);
    printf("\nAverage Turnaround Time=%f\n",avg_tatt);

    return 0;	
}
