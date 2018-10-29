//By: Vijay Patel
//Oct 21, 2018
//McMaster University
//Computer Eng and Management

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************Question 1***********************************************************/
char *my_strcat( const char * const str1, const char * const str2); //function prototype
int main()  //Main function to test program
{
    printf("%s \n", my_strcat("Hello", "world!"));
    return 0;
}
char *my_strcat( const char * const str1, const char * const str2)
{
    int n, i;
    char *concat;
    n = strlen(str1) + strlen(str2) + 1;
    concat = (char *)malloc(n*sizeof(char));
    for (i=0; i<strlen(str1); i++)
    {
        concat[i] = str1[i];
    }
    for (i; i<n-1; i++)
    {
        concat[i] = str2[i-strlen(str1)];
    }
    concat[n-1]= '\0';
    return concat;
}

/***********************************************************Question 2***********************************************************/
//Create Struc
typedef struct
{
    int idNum;
    char firstName[15], lastName[15];
    int project1, project2;
    float courseGrade;
} student;

//Function Prototypes
student **create_class_list(char *filename, int *sizePtr);
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void compute_final_class_grades(student **list, int size);
void output_final_course_grades(char *filename, student** list, int size);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);
void destroy_list(student **list, int *sizePtr);

//Main Function To Test CodestudentList[i]= calloc(1, sizeof(student));
int main(void)
{
    int classSize, a, b;
    student** ptrA;
    ptrA= create_class_list("classlist.txt", &classSize);

    //Test for Function create_class_list()
    for (int i=0; i<classSize; i++)
    {
        printf("%d %s %s\n", ptrA[i]->idNum, ptrA[i]->firstName, ptrA[i]->lastName);
    }

    //Test for Function find()
    printf("%d", find(9000, ptrA, classSize));

    //Test for Function classgrade()
    input_grades("classgrade.txt", ptrA, classSize);
    for (int i=0; i<classSize; i++)
    {
        printf("%d %s %s %d %d\n", ptrA[i]->idNum, ptrA[i]->firstName, ptrA[i]->lastName, ptrA[i]->project1, ptrA[i]->project2);
    }

    //Test for compute_final_course_grades()
    compute_final_class_grades(ptrA, classSize);
    for (int i=0; i<classSize; i++)
    {
        printf("%d %s %s %d %d %0.1f\n", ptrA[i]->idNum, ptrA[i]->firstName, ptrA[i]->lastName, ptrA[i]->project1, ptrA[i]->project2, ptrA[i]->courseGrade);
    }

    //Test for output_final_course_grades()
    output_final_course_grades("finalcoursegrades.txt", ptrA, classSize);
    FILE *finalgrades=fopen("finalcoursegrades.txt", "r");
    fscanf(finalgrades, "%d", &c);
    printf("%d\n", c);
    for(int i=0; i<classSize; i++)
    {
        fscanf(finalgrades, "%d %f", &a, &b);
        printf("%d %0.1f\n", a, b);
    }


    //Test for void print_list()
    print_list(ptrA, classSize);

    //Test for withdraw()
    withdraw(9000, ptrA, &classSize);
    printf("\nThe class has %d students now.\n", classSize);

    //Test for destroy_list()
    destroy_list(ptrA, &classSize);
    printf("\nThe class has %d students now.\n", classSize);
    print_list(ptrA, classSize);

    return 0;
}

//create_class_list function
student **create_class_list(char *filename, int *sizePtr)
{
    FILE *classList=fopen(filename, "r"); //open file
    fscanf(classList, "%d", sizePtr); //scan the first integer to determine how many students there are
    student** studentList= malloc(*sizePtr*sizeof(student*)); //allocate memory for an array of 3 pointers to struc of type student
    for (int i=0; i<*sizePtr;i++) // for loop that runs to record students
    {
        studentList[i]= calloc(1, sizeof(student)); //splits the memory we created above for each student. Used calloc because it initializes all non inputed value to 0 (project1, project2, coursegrade.)
        fscanf(classList, "%d%s%s", &(studentList[i]->idNum), &(studentList[i]->firstName), &(studentList[i]->lastName));
    }
    fclose(classList);  //closes the file
    return studentList;
}

//find function
int find(int idNo, student **list, int size)
{
    for (int i=0; i<size; i++)
    {
        if(list[i]->idNum ==idNo)
            return i;
    }
    return -1;
}

//input_grades function
void input_grades(char *filename, student **list, int size)
{
    FILE *gradesList=fopen(filename, "r");
    int id=0, j;
    for (int i=0; i<size; i++)
    {
        fscanf(gradesList, "%d", &id); //scans the first number in the line (idNo)
        j= find(id, list, size); //allocates in the index in the classlist to j
        fscanf(gradesList, "%d %d", &(list[j]->project1), &(list[j]->project2)); //scans the other 2 numbers and changes the value of project1 and project2
    }
    fclose(gradesList);
}

//compute_final_course_grades function
void compute_final_class_grades(student **list, int size)
{
    for (int i=0; i<size; i++)
    {
        list[i]->courseGrade= ((float)list[i]->project1 + (float)list[i]->project2)/2; //converted the project grades to float so that it wouldnt round to an interger.
    }
}

//output_final_course_grades function
void output_final_course_grades(char *filename, student** list, int size)
{
    FILE *output=fopen(filename, "w");
    fprintf(output, "%d\n", size);
    for(int i=0; i<size; i++)
    {
        fprintf(output, "%d %f\n", list[i]->idNum, list[i]->courseGrade);
    }
    fclose(output);
}

//print_list function
void print_list(student **list, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("ID: %d, name: %s %s, project 1 grade: %d, project 2 grade: %d, final grade: %.1f\n", list[i]->idNum, list[i]->firstName, list[i]->lastName, list[i]->project1, list[i]->project2, list[i]->courseGrade);
    }
}

//withdraw function
void withdraw(int idNo, student **list, int *sizePtr)
{
    int j=0; //variable x is created to change the size of the array and j is to check if the id is in the array
    for(int i=0; i< *sizePtr; i++)
    {
        if(list[i]->idNum == idNo)
        {
            j+=1; //if the list does not contain the id, j will increment by 1 and the print statement will print
        }
    }
    if(j==0)
    {
        printf("The id you are trying to withdraw is not in the list");
    }
    for(int i=0; i<*sizePtr; i++)
    {
        if(list[i]->idNum == idNo)
        {
            free(list[i]); //finds idNo and its index location
            for(int j=i; j<(*sizePtr)-1; j++) //loop shifts all pointers down by 1
            {
                *(list[j])= *(list[j+1]);
            }
            list[*sizePtr-1]=NULL;
            *sizePtr -= 1;
        }
    }
}

//destroy_list function
void destroy_list(student **list, int *sizePtr)
{
    for(int i=0; i<*sizePtr; i++) //Goes thorugh each pointer in the pointer array, deallocates it and assigns it to NULL
    {
        free(list[i]);
        list[i]=NULL;
    }
    *sizePtr=0; //Sets size variable to 0
}


/************************************************************Question 3*************************************************************/
//Function Prototype
char **read_words(const char *input_filename, int *nPtr);
void sort_words(char **wordList, int *nPtr);
void output_words(char **wordList, int *nPtr);

int main()
{
    int num;
    char** ptrA;
    ptrA= read_words("words.txt", &num);
    sort_words(ptrA, &num);
    output_words(ptrA, &num);
    return 0;
}

char **read_words(const char *input_filename, int *nPtr)
{
    FILE *wordFile = fopen(input_filename, "r");
    fscanf(wordFile, "%d", nPtr); //scans for the number of words
    char **wordList = malloc(*nPtr*sizeof(char*)); //allocates memory for the array
    for(int i=0; i<*nPtr; i++)
    {
        wordList[i]= malloc(sizeof(char)); //allocates memory needed for each word
        fscanf(wordFile, "%s", wordList[i]); //scans the word
    }
    fclose(wordFile); //closes file
    return wordList;
}

void sort_words(char **wordList, int *nPtr)
{
    char *temp =malloc(sizeof(char));  //allocate memory for a temp pointer
    for(int i=0; i<*nPtr; i++)
    {
        for (int j=i+1; j<*nPtr; j++)
        {
            if(strcmp(wordList[i], wordList[j])>0)
            {
                temp= wordList[j];
                wordList[j]= wordList[i];
                wordList[i]=temp;
            }
        }
    }
}

void output_words(char **wordList, int *nPtr)
{
    for(int i=0; i<*nPtr; i++)
    {
        printf("%s\n", wordList[i]);
    }
}



