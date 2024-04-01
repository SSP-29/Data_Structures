
#include <stdio.h>
int main()
{
    int num;
    FILE *input,*output;
    input=fopen("input.txt","r");
    if(input==NULL)
    {
        perror("\nError in opening the file\n");
        return 1;
    }
    fscanf(input,"%d",&num);
    int flag=0;
    for (int i = 2; i <=(num/2); i++) 
    {
        if(num%i==0)
        {
            flag=1;
            break;
        }
    }

    output=fopen("output.txt","w");
    if(flag==0)
    {
        fprintf(output,"Is prime number");
    }
    else
    {
        fprintf(output,"Not a prime number");
    }
    return 0;
}
