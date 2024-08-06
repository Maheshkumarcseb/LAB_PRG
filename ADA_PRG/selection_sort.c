#include<stdio.h> 
#include<conio.h> 
#include<time.h> 
#include<dos.h> 
void selsort(int a[],int n) 
{ 
int i,j,small,pos,temp; 
for(j=0;j<n-1;j++) 
{ 
small=a[j]; 

 
  pos=j; 
  for(i=j+1;i<n;i++) 
  { 
   if(a[i]<small) 
   { 
    small=a[i]; 
    pos=i; 
   } 
  } 
  temp=a[j]; 
  a[j]=small; 
  a[pos]=temp; 
 } 
} 
void main() 
{ 
 int a[10],i,n; 
 clock_t start,end; 
 float dura; 
//  clrscr(); 
 printf("\nEnter the n value:"); 
 scanf("%d",&n); 
 printf("\nEnter the array:"); 
 for(i=0;i<n;i++) 
 scanf("%d",&a[i]); 
 start=clock(); 
 selsort(a,n); 
 delay(100); 
 end=clock(); 
 dura=(end-start)/CLK_TCK; 
 printf("\nTime taken is:%f",dura); 
 printf("\nSorted array is:"); 
 for(i=0;i<n;i++) 
 printf("%d ",a[i]); 
//  getch(); 
} 