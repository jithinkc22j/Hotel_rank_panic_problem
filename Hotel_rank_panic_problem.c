//Created by Jithin K C
#include <stdio.h>

//Function Declaration - Hotel_rank_panic_problem
int Hotel_rank_panic_problem(int,int,int a[],int b[]);

int main()
{
    int c,i,j,n,k,Check_in[100],Check_out[100],out=0,c2=0;

    scanf("%d", &n);// Number of customers -n
    scanf("%d", &k);// customer-Threshold -K
  
    //Constrain-1 1<= n <=2*10^5 & k<=10^9
    if(1<=n && n<=2*10^5 && k<=10^9)
    {
        c=2; //Check-in , Check-out [column of matrix =2]
    
    // Reading Check-in and Check-out Time 
    //-------------------------------------
     for (i = 0; i < n; i++)
        {  
            scanf("%d", &Check_in[i]);
            scanf("%d", &Check_out[i]);
        }
    //-------------------------------------
    
    //Constrain-2 1<= Check-in[i],Check-out[i]
    //--------------------------------------
     for (i = 0; i < n; i++)
     {
         //Checking Constrain-2
         if(Check_in[i]==0 || Check_out[i]==0)
         {
             c2=1;
             //Constrain-2 is true break from loop  
             break;
         }
     }
     //--------------------------------------
     
     // Constrain-2 is FALSE
     //---------------------
     if(c2==0)
         { 
             //Calling Hotel_rank_panic_problem()
            out=Hotel_rank_panic_problem(n,k,Check_in,Check_out);
         }
    //-----------------------
    
     if(out==0)
        { 
            // No panic Time period / Constrain-2 is true 
            printf("NULL");
         }
     else
        {   // Panic Time period
            printf("%d",out);
        }
    }
return 0;
}

// Functiion Definition - Hotel_rank_panic_problem()
int Hotel_rank_panic_problem(int n,int k,int Check_in[],int Check_out[])
{
    int c,i,j,temp,s=0,a[100][100];
    
 // Creating Matrix 'a' Using Check_in & Check_out array ; 
 //------------------------------------------------------
  for (i = 0; i < n; i++)
    {
        a[i][0]=Check_in[i];
        a[i][1]=Check_out[i];
    }
 //-------------------------------------------------------
 
//Checking Whether the Number of customers (n) exceeded the Threshold (K)
//-----------------------------------------------------------------------
    if(n>=k)
    {
    // Sorting the Matrix based on Check-in Time
        for (i = 0; i < n; ++i) 
        {     for (j = i + 1; j <= n; ++j)
                {
                    if (a[i][0] > a[j][0]) 
                    { 
 
                        temp =  a[i][0];
                        a[i][0] = a[j][0];
                        a[j][0] = temp;
                        temp=a[i][1];
                        a[i][1] = a[j][1];
                        a[j][1] = temp;
 
                    }
                }
        }
  
        
// Calculating Panic Time period     
//---------------------------------
        for (i = 0; i < n; ++i)
        {
            // Checking Whether Any new customer arrive befor previous customer check-out
           if(a[i][1]>=a[i+1][0])
           {   // Checking Whether Any Overlap between check-out Time of customers
               if(a[i+1][1]>=a[i][1])
               {
                   // Calculating Panic Time period
                   temp=a[i][1]-a[i+1][0];
                  //printf("%d-%d",a[i][1],a[i+1][0]);
                  // printf("%d",temp);
                   
               }
               else
               {
                    // Calculating Panic Time period
                   temp=a[i+1][1]-a[i+1][0];
                   //printf("l-%d",s);
               }
               // Calculating Panic Time period
               s=s+temp;
           }
        }
         // Panic Time period
        return s;
    }
}
