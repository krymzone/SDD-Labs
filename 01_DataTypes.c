#include <stdio.h>
#include <malloc.h>

#define BYTEARRAY_SIZE 10
#define LINE_SIZE 6
#define COLUMN_SIZE 6

int main()
{
    char x = 65;
    unsigned char y = -2;

    float z = (float)65.64;

    char* p = NULL; // Declare a pointer to char 'p' and initialize it to NULL (no memory allocated yet)
    printf("Memory Address of location p = %p \n", &p);
    printf("Content of location p = %p \n \n", p);
    // printf("Content of pointed location p = %d \n", *p); // This would cause a segmentation fault because p is NULL

    p = &x; // Set pointer 'p' to point to the memory address of variable 'x'
    printf("Memory Address of location p = %p \n", &p);
    printf("Content of location p = %p \n", p);
    printf("Content of pointed location p = %d \n \n", *p);

    p = (char*)malloc(1 * sizeof(char)); // Dynamically allocate 1 byte of memory and cast the returned pointer to a char pointer
    printf("Memory Address of location p = %p \n", &p);
    printf("Content of location p = %p \n", p);
    printf("Content of pointed location p = %d \n \n", *p);

    *p = x; // Dereference 'p' and assign the value of 'x' (65) to the allocated memory location
    printf("Memory Address of location p = %p \n", &p);
    printf("Content of location p = %p \n", p);
    printf("Content of pointed location p = %d \n \n", *p);

    free(p); // Free the dynamically allocated memory to prevent memory leak

    p = (char*)malloc((BYTEARRAY_SIZE + 1) * sizeof(char)); // Dynamically allocate memory for a byte array of size BYTEARRAY_SIZE + 1
    // The +1 is used to reserve space for the null terminator '\0', which is needed for a valid string.
    
    for (unsigned char i = 0; i < BYTEARRAY_SIZE; i++) // Loop through each element in the byte array
    {
        p[i] = x + i; // Assign the value of 'x + i' to each byte of the array, effectively storing values 65, 66, ..., 74
    }

    p[BYTEARRAY_SIZE] = 0; //save the null byte right after the last item in the bytearray
    
    for (unsigned char i = 0; i < BYTEARRAY_SIZE; i++)
    {
        printf("%d--> %c\n", p[i], p[i]); // Print the integer value (as %d) and the character value (as %c) of the current element p[i] in the array
    }

    printf("\n%s\n", p); // Print the string starting from the memory address pointed to by 'p'. 
    free(p);

    char v[BYTEARRAY_SIZE + 1];
    p = v; //p contains the starting point (mem address) of the array v

    for (unsigned char i = 0; i < BYTEARRAY_SIZE; i++)
    {
        v[i] = x + i;
    }

    v[BYTEARRAY_SIZE] = 0;
    printf("\n%s\n", p);

    char** pM = NULL;
    //matrix allocation
    pM = (char**)malloc(LINE_SIZE * sizeof(char*));//allocation of the 1st level of the matrix in heap
    for (unsigned char i = 0; i < LINE_SIZE; i++) 
    {
        pM[i] = malloc(COLUMN_SIZE * sizeof(char)); //allocation of line #i; heap memory address stored on intermediary level
    }

    //store relevant contet over reach matrix item accessed y pM[i][j]

    // matrix deallocation
    //deallocate the farest heap locations ( the lines with the actual values)
    for (unsigned char i = 0; i < LINE_SIZE; i++) 
    {
        free(pM[i]);//deallocate line #i
    }
    //deallocate the nearest heap location
    free(pM); // deallocate the intermediary array of addresses to the lines

	return 0;
}