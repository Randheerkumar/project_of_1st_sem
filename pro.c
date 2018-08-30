#include <stdio.h>
#include<string.h>

int main()
{
char str[30],ch;int n=0,lat=0,lon=0,l,i,j,k=0,m=0;
printf("enter the choice \n 1.for entering city name \n 2.for entering latitude and longitude");
scanf("%d\n",n);
if(n==1)
{  printf("enter city name");
   fgets(str,30,stdin);

}
else if(n==2)
{
  printf("enter latitude");
  scanf("%d",lat);
  printf("enter longitude");
  scanf("%d",lon);

}
else
{
  printf("you have entered wrong choice");
}
l=strlen(str)-1;

for(i=0;i<1000;i++)
{
	for(j=0;j<l;j++)
{
ch=arr[i].city[j];
if(str[j]==ch);
  k++;

}
if(k==l)
m=i;
if(k==(l-1))
printf("did u mean%s")

}






}
