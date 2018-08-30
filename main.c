/*file name - hell.c
  Ic150p project
  database name - p21.txt
  readme.txt
  date modified - 30-11-2016
*/




#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>
#define R 6400
#define pi 3.14285714

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:Structure is exclusively used  to store the information from the database.:*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
typedef struct{
                char city[100];
                double lat;
                double lon;
                char state[100];
	      char lang[20];
              }cityinfo;

double deg2rad(double);
double rad2deg(double);

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:This function takes 5 arguement and calculates the distance from one specified cordinate to another.:*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = rad2deg(dist);
  dist = dist * 60 * 1.1515;
  switch(unit) {
    case 'M':
	
      break;
    case 'K':
      dist = dist * 1.609344;
	
      break;
    case 'N':
      dist = dist * 0.8684;
	
      break;
  }
  return (dist);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts decimal degrees to radians             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double deg2rad(double deg) {
  return (deg * pi / 180);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  This function converts radians to decimal degrees             :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
double rad2deg(double rad) {
  return (rad * 180 / pi);
}

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:It is the compare function to sort a given array of data.        :*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
int cmpfunc (const void * a, const void * b)
{
return ( *(double*)a - *(double*)b );
}


int main()
{
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:1st Part                                                         :*/
/*:This part reads the data from the database provided p21.txt.::::::*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
	FILE *f;
    char a[300],ch='a',b[7],c[7];
    int i=0,count=0,o=0,p=0,q=0,r=0,s=0,la=0;
    cityinfo arr[1000];
    f = fopen("p21.txt","r");
    while(fgets(a,sizeof(a),f)!=NULL)
    {
    count=0;
        i=0;
        p=0;
        q=0;
        r=0;
        s=0;
        la=0;
        ch='a';

        while(ch!='\0')
        {
            ch=a[i];
            if(ch == 39)
            {
                count++;
            }

            if(count==1)
            {
                i++;
                while(a[i]!=39)
                {
                    arr[o].city[p]=a[i];
                    p++;
                    i++;
                }
                arr[o].city[p]='\0';
                count++;
            }
            if(count==3)
            {
                if(a[i]!=39)
                {
                    if(a[i]!=32)
                    b[r]=a[i];
                    r++;

                }

            }
            arr[o].lat=atof(b);
            if(count==5)
            {
                if(a[i]!=39)
                {
                     if(a[i]!=32)
                     c[s]=a[i];
                     s++;
                }
            }
            arr[o].lon=atof(c);
            if(count==7)
            {
                i++;
                while(a[i]!=39)
                {
                    arr[o].state[q]=a[i];
                    q++;
                    i++;
                }
                arr[o].state[q]='\0';
                count++;
            }
	if(count==9)
            {
                i++;
                while(a[i]!=39)
                {
                    arr[o].lang[la]=a[i];
                    la++;
                    i++;
                }
                arr[o].lang[la]='\0';
                count++;
            }
            i++;
        }
        o++;
    }

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:2nd Part                                                                                        :*/
/*:This part of code asks for input from user wether he wants to enter the city name or coordinates:*/
/*:Additonaly it also checks if the user has entered correct city name or not.If the input is wrong */
/*           it gives user a list of cities matching to the entered string and select               */
/*:                             the desired city from given list.                                  :*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/


	 char str[30],chr,cht;
	 int valid=0,l,j,m=0,y=0,t=0,x=0,e,d=0,z=0,g[20],tm=0,tr=0;
           double lat=0.0,lon=0.0;
          
	 printf("Enter the choice. \n 1. For entering city name. \n 2. For entering latitude and longitude.\n");	 
            double n=0;
	 while(n<1 || n>2)			//Error Handling
          {
              //scanf("%d",&n);
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&n)!=1 ||((n-(int)n)!=0))
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("wrong input \n enter again");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(n<1 || n>2)
            {
             printf("Enter correct input\n");
             valid=0;
            }



           if(n==1)
           {  
             	printf("Enter city name:\n");
             int value=0;	
              while(value==0)			//Error Handling
              {
                 i=0;
                scanf("%s",str);
                if(!(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'))
                 {
                   printf("You have entered invalid entry enter again:\n");
                    value=0;
                 }
                 else
                   value=1;   
                i++; 
             }


                    while(str[tr]!='\0')
                      {
                      cht=str[tr];
                      if(cht>='A' && cht<='Z')
                          str[tr]=cht+32;
                        
                        tr++; 

                       }
                    // printf("%s",str);
                     cht=str[0];
                    if(cht>='a' && cht<='z')
                       str[0]=cht-32;
  

           }
           else if(n==2)
           {
             	printf("Enter Latitude:  ");

                lat =0;
	 while(lat<6.764678 || lat>35.674452)  		//Error Handling
          {
              
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&lat)!=1)
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("wrong input \n enter again:\n");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(lat<6.764678 || lat>35.674452)		//Error Handling
            {
             printf("Give latitude is out of india please enter indian latitude..(Lying between 6.764678 and 35.674452):\n ");
             valid=0;
            }

          }

	
    	printf("Enter Longitude:  ");
          
               lon =0;
	 while(lon<68.01325 || lon>97.4023)		//Error Handling
          {
              
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&lon)!=1)
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("wrong input \n enter again:\n");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(lon<68.01325 || lon>97.4023)	//Error Handling
            {
             printf("Give longitude is out of india please enter indian longitude..(Lying between 68.01325 and 97.4023) :\n");
             valid=0;
            }

          }


          }
          else
          {
             	printf("You have entered wrong choice.\nEnter again:");
          }
}
          l=strlen(str);
        if(n==1)
        {  
         for(i=0;i<1000;i++)
            {
              y++;
              int k=0;
	      for(j=0;j<l;j++)
                 {
              
                	chr=arr[i].city[j];
                	if(str[j]==chr)
                   	     k++;
                    
              
                 }
            	if(k==l)
             	{
              	          m=i;
              		lat=arr[i].lat;
              		lon=arr[i].lon;
                              //printf("%s",arr[i].city);
                              break;
            	 }
            	else if(k==(l-1) && arr[i].city[l]=='\0')
            	{
            	  g[x]=i;
            	  x++;
                          
            	}
          
         	   }
         if(x==0 && m==0 && lat==0.0 && lon==0.0)
          	{ 
          	printf("City is not found in database.\n");
          		tm++;
          	}       
        } 
 
         //g[x]='\0';
         if(x!=0 && m!=i)
        {
         	printf("Did you mean\n");

         	for(z=0;z<x;z++)
           {
           o=g[z];
           printf("%d  %s\n",(z+1),arr[o].city);
           }

        printf("Please enter the city no:\n");
        
        
            n=0;
	 while(n<1 || n>x)			//Error Handling
          {
              
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&n)!=1 ||((n-(int)n)!=0))
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("wrong input \n enter again");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(n<1 || n>x)
            {
             printf("enter correct input");
             valid=0;
            }
          }

             e=((int)n);
         if(e>0 && e<=(x))
         {
	         o=g[e-1];
	         lon=arr[o].lon;
	         lat=arr[o].lat;
	         
         }

         else         {
		printf("You have entered wrong choice.\n\n");
           
         }

      }
	
	
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*:3rd Part                                                                                             :*/
/*:This part of code takes the coordinates intended by user and calculates the distance from all cities.:*/
/*:Asks the user his desired destination city from the drop down list and prints the info for that city.:*/
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

	if(tm!=1)	
	{
		fflush(stdin);
	int w=0;
	
	double a11,b11,c11,d11;
		b11=lon;
		a11=lat;
	char x1='K';
	
	double dist[1000],sortdist[1000];
	for(int w=0;w<1000;w++)
	{
		d11=arr[w].lon;
		c11=arr[w].lat;		
		dist[w]=distance(a11,b11,c11,d11,x1);
		sortdist[w]=distance(a11,b11,c11,d11,x1);
	}
	
	qsort(sortdist,1000,sizeof(double),cmpfunc);
	
	
	 printf("\nEnter the number of nearest cities list you want to get.\n");
        
              n=0;
	 while(n<1 || n>1000)		//Error Handling
          {
              
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&n)!=1 ||((n-(int)n)!=0))
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("wrong input \n enter again");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(n<1 || n>1000)
            {
             printf("enter correct input:");
             valid=0;
            }


          }         




	int da;
          da=((int)n);
	
	  

	int arr1[1000];
		for(int g=0;g<da;g++)
		{	int t=0;
			while(sortdist[g]!=dist[t])
			{ t++;}
			arr1[g]=t;
			printf("\n %d %s \n",g+1,arr[t].city);
		}
	    
		
	 printf("\n Enter the corresponding number preceeding your destination city.\n");

                n=0;
	 while(n<1 || n>da)			//Error Handling
          {
              
              valid=0;
             while(valid==0)
             {
              if(scanf("%lf",&n)!=1 ||((n-(int)n)!=0))
                 {
                  char ch[20];
                  scanf("%s",ch);
                  printf("Wrong Input \n Enter again:");
                  valid=0;
                 }
              else valid =1;
             }
          
            if(n<1 || n>da)
            {
             printf("Enter correct input:");
             valid=0;
            }
       }

	int mo;
            mo=((int)n);
	
		

	int u;
	u=arr1[mo-1];

	printf("\n............\n");
	printf("City Name: %s\n\n",arr[u].city);
	printf("Latitude of the city: %lf\n\n",arr[u].lat);
	printf("Longitude of the city: %lf\n\n",arr[u].lon);
	printf("State Name: %s\n\n",arr[u].state);
	printf("Majorly spoken local language: %s\n\n",arr[u].lang);
	printf("Distance from your current position(AS THE CROW FLIES) is %lf Kms.\n\n",sortdist[mo-1]);
	}	
		
	
	
	
	
}
