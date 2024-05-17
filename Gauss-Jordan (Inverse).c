
/*finding inverse of a Matrix through Gauss-Jordan Method*/

#include<stdio.h>
#include<math.h>

void swap( float *a , float *b)/*swapping function*/
{ float temp;
 temp = *a;
*a = *b ;
*b = temp;}

void main()
{ float a[20][20],temp;
int i,j,k,n;

printf("\n Please enter the size of the martrix: ");
scanf("%d", &n);

printf("\n Please enter the elements :");
for(i=0;i<n;i++)
{ for(j=0;j<n;j++)
  { printf("\n please enter a[%d] [%d]: ",i+1,j+1);
    scanf("%f",&a[i][j]);
  }
}    
for(i=0;i<n;i++)/*it expands the Matrix given by user to an augmented Matrix*/
{ for(j=n;j<2*n;j++)
  { if(j==i+n)
      a[i][j]=1;
    else
      a[i][j]=0;}}
      
for(i=0;i<n-1;i++)
{ for(j=i+1;j<n;j++)
  { if(fabs(a[i][i])<fabs(a[j][i]))/*partial pivoting*/
    { for(k=0;k<2*n; k++)
        swap(&a[i][k],&a[j][k]);}}
  for(j=i+1;j<n;j++)/*it transforms the user-given Matrix into a upper-triangular Matrix*/
  { temp=a[j][i]/a[i][i];
    for (k=0;k<2*n;k++)
    { a[j][k]=a[j][k]-temp*a[i][k]; }}}

for(i=n-1;i>=0; i--)/*it transforms the upper-triangular Matrix into a identity Matrix*/
{  temp = a[i][i];
   for (k=0;k<2*n; k++)
   {  a[i][k]=a[i][k]/temp;}
   for(j=i-1;j>=0;j--)
   {  temp=a[j][i];
      for (k=0;k<2*n;k++)
      { a[j][k]=a[j][k]-a[i][k]*temp;}}}
     

printf("\n The solution is :"); 
printf("\n");
for(i=0;i<n;i++)
{ for(j=n;j<2*n;j++)
{ printf("%f\t",a[i][j]);}
printf("\n");}}