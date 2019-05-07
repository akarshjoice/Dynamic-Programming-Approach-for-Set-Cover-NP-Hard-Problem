#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char str[1000];

char token[1000];

char* strcpyn(char d[],char s[])
{
 long int c = 0;
  
 
 
  while (s[c] != '\0') {
    d[c] = s[c];
    c++;
  }
 
  d[c] = '\0';
 
  return d;
}



void splitstring(char str1[],long int k)
{
   long int start=0,count=0;
   long int i,j;

  for(i=0;i<strlen(str1);i++)
     { //printf("%d",i);
          if(str1[i]=='#')
             {   
                count++;
                if(count==k)
                       break;
                start=i+1;
                
              }
     }

long int t=0;
for(j=start;j<i;j++)
  {
   token[t++]=str1[j];
  }
token[t]='\0';
}

void splitstringglobal(long int k)
{
   long int start=0,count=0;
   long int i,j;

  for(i=0;i<strlen(str);i++)
     { //printf("%d",i);
          if(str[i]=='#')
             {   
                count++;
                if(count==k)
                       break;
                start=i+1;
                
              }
     }

long int t=0;
for(j=start;j<i;j++)
  {
   token[t++]=str[j];
  }
token[t]='\0';
}

/*char* splitstring(char st[],int k) 
{ 
  
    
    char *token = strtok(st, "#"); 
    k--; 
    while (token != NULL && k!=0) 
    { 
        token = strtok(NULL, "#");
        k--; 
    }  
  return token;
} 

char* splitstringglobal(int k) 
{ 
  
    
    char *token = strtok(str, "#"); 
    k--; 
    while (token != NULL && k!=0) 
    { 
        token = strtok(NULL, "#");
        k--; 
    }  
  return token;
} */

char* diff(char str1[],char str2[])
{ char *result=(char *) malloc(1000);
  
 long  int flag=0;
  long int l=0;
  for(long int i=0;i<strlen(str1);i++)
     {  flag=0;
    for(long int j=0;j<strlen(str2);j++)
        {  if(str1[i]==str2[j])
               {      
                      flag=1;
                      break;
               }
           
        }
if(flag==0)
        result[l++]=str1[i];
                  
      }
result[l]='\0';
//printf("%s",result);
char* zero="0";
if(l==0)
    return zero;


 return result;
       

}

long int pos(char str1[],char str2[])
{

long int count1=0,count2=0,i,j,flag;



//puts("Enter a string:");
//gets(str);

//puts("Enter search substring:");
//gets(search);

while (str1[count1]!='\0')
count1++;

while (str2[count2]!='\0')
count2++;

long int count=0;
for(i=0;i<=count1-count2;i++)
{  
for(j=i;j<i+count2;j++)
{
flag=1;
if (str1[j]!=str2[j-i])
{
flag=0;
break;
}
}
if (flag==1)
break;
}



for(i=0;i<j;i++)
{ 
  if(str1[i]=='#')
        count++;

}
count++;
return count;

}
void subset(long int arr[], long int data[], long int start, long int end, long int index, long int r)
{
    long int j, i;
    char s[1000];
    if (index == r) {
        for (j = 0; j < r; j++)
               s[j]=data[j] + '0';
      s[j]='\0';
                   
            strcat(str,s);
            strcat(str,"#");     
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        subset(arr, data, i+1, end, index+1, r);
    }
}


void printsubset(long int arr[], long int n, long int r)
{
    long int data[r];
    subset(arr, data, 0, n - 1, 0, r);
}

long int min(long int a ,long int b)
  {
    
    if(a<b)
          return a;
    else
          return b;

 } 

long int power(int a,int b)
  {  long int tmp=1;
     for(long int i=1;i<=b;i++)
           tmp=tmp*a;

    return tmp;
  }




void main()
{ 
 strcpyn(str,"0");
 char M[1000],N[1000];
 long int ans[1000][1000];
 long int n,m;
 char tmp[1000];
printf("\nEnter no.of elements in MAIN set:");
scanf("%ld",&n);
printf("\nEnter main set elements without leaving any blackspace:");
scanf("%s",N);
printf("\nEnter no.of collection:");
scanf("%ld",&m);
printf("\nEnter each collection with # at the end:");
scanf("%s",M);

// enteragain N
long int arr[1000];
    printf("\nPlease Confirm Your MAIN set by Entering again\n");
    printf("\nEnter no.of elements in main set: ");
    scanf("%ld", &n);
    printf("\nEnter each element in main set and Press Enter\n");
    for (long int  i = 0; i < n; i++)
    {
	scanf("%ld", &arr[i]);
    }
   for(long int k=0;k<=n;k++)
    printsubset(arr, n, k);
    strcat(str,"\0");
//



long int l=power(2,n);

for(long int i=1;i<l;i++)
     ans[i][0]=1000;

for(long int j=0;j<=m;j++)
     ans[0][j]=0;
//printf("%s\n",str);
char str1[1000];
char M1[1000];
for(long int i=1;i<l;i++)
    {   // printf("%ld-%s\n",i,str);
  
      splitstringglobal(i+1);
      strcpy(tmp,token);
     
  
   for(long int j=1;j<=m;j++)
      {
         splitstring(M,j);
     //     printf("%s\n",token);
        ans[i][j]=min(1+ans[pos(str,diff(tmp,token))-1][j-1],ans[i][j-1]);
       }
 

    }

//for(long int i=0;i<l;i++)
//{  // printf("%ld",i);
  //  for(long int j=0;j<=m;j++)
     // printf("%ld ",ans[i][j]);
  //printf("\n");


if(ans[l-1][m]==1000)
    printf("NOT POSSIBLE\n");
else
    printf("NUMBER OF SUBSETS REQUIRED IS %ld \n",ans[l-1][m]);
 }


