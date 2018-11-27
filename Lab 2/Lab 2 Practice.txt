//Vijay Patel
//Oct 01, 2018
//McMaster Univeristy
//Computer Eng and Management

//This respository is incomplete. I was only able to complete up to question 7.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*************************************************Question 1*************************************************/
void print_vector(double array[], int size);
void print_vector(double array[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%lf, ", array[i]);
    }
}

void add_vectors(double vector1[], double vector2[], double vector3[], int n);
void add_vectors(double vector1[], double vector2[], double vector3[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       vector3[i]= vector1[i] + vector2[i];
    }
}

double norm2(double vec1[], double vec2[], int n);
double scalar_prod(double vec3[], double vec4[], int m);
double norm2(double vec1[], double vec2[], int n)
{
    int temp;
    double scalprod;
    scalprod = scalar_prod(vec1,vec2, n);
    temp = sqrt(scalprod);
    return temp;
}
double scalar_prod(double vec3[], double vec4[], int m)
{
    double temp1=0; int i;
    for(i=0;i<m;i++)
    {
        temp1+= vec3[i] * vec4[i];
    }
    return temp1;
}

/*************************************************Question 2*************************************************/
void sorted(int array[], int n);
void sorted(int array[], int n)
{
    int i, temp=0;
    for(i=0; i<n-1; i++)
    {
        if(array[i]>array[i+1])
        {
            temp += 1;
        }
    }
    if(temp>0)
    {
        printf("The array is not sorted.");
    }
    else
    {
        printf("The array is sorted.");
    }
}

/*************************************************Question 3*************************************************/
void freq(int array[], int n, int numb);
void freq(int array[], int n, int numb)
{
    int i, temp=0;
    for(i=0; i<n; i++)
    {
        if (array[i]== numb)
        {
            temp += 1;
        }
    }
    printf("The number %d apprears in the array exactly %d times.\n", numb, temp);
}

/*************************************************Question 4*************************************************/
void change(int x[], int n);
void change(int x[], int n)
{
    int i, j=0, temp[n];
    for(i=0; i<n; i++)
    {
        if(x[i]!=0)
        {
            temp[j]=x[i];
            j++;
        }
    }
    for(j; j<n; j++)
    {
        temp[j]=0;
    }
    for(i=0; i<n; i++)
    {
        x[i]= temp[i];
    }
}

/*************************************************Question 5*************************************************/
#define N 3
int is_diag_dom(int mat[][N]);
int is_diag_dom(int mat[][N])
{
    int i, j, sum, check=0;
    for(i=0; i<N; i++)
    {
        sum =0;
        for(j=0; j<N; j++)
        {
            if(j!=i)
            {
                sum += mat[i][j];
            }
            if(sum>fabs(mat[i][i]))
            {
                check +=1;
            }
        }
    }
    if(check==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*************************************************Question 6*************************************************/
#define N 4
void scanorder(int mat[][N]);
void scanorder(int mat[][N])
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<=i; j++)
        {
            printf("%d, ", mat[i-j][j]);
        }
    }
    for(j=1; j<N; j++)
    {
        for(i=N-1; i>=j; i--)
        {
            printf("%d, ", mat[i][j+(N-1)-i]);
        }
    }
}

/*************************************************Question 7*************************************************/
int is_toeplitz(int a[][N], int m);
int is_toeplitz(int a[][N], int m)
{
    int rowNum, colNum;
    for (rowNum=0; rowNum<m-1; rowNum++)
    {
        for (colNum=0; colNum<N-1; colNum++)
        {
            if (a[rowNum][colNum] != a[rowNum+1][colNum+1])
            {
                return 0;
            }
        }
    }
    return 1;
}

/*************************************************Question 8*************************************************/\
//NOT DONE
void letter_freq(const char word[], int freq[]);
int main(void)
{

    return 0;
}
void letter_freq(const char word[], int freq[])
{
    int letter, i, frequency;
    for(letter=0; letter<=26; letter++)
    {
        frequency= 0;
        for(i=0; word[i]!='\0'; i++) //goes through each letter
        {
            if (i==j+ ||i==)
        }
    }

}




