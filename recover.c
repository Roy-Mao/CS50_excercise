#include <stdio.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Should give and only give one arg.\n");
        return 1;
    }
    FILE* f;                                                    //create a pointer to file
    f = fopen(argv[1], "r");                                 //initiate the pointer to point at inputfile
    if (f == NULL)                                              //Check if the pointer is null
    {
        fprintf (stderr, "Error opening the file.");
        return 2;
    }
    
    FILE* fw;                                                   //create a pointer to another file;
    fw = NULL;                                                  //initialize the pointer to Null
    int count = 0;                                              // count the JPEGS for the naming use. Initialize to 0
    uint8_t buffer[512];                                        //create a buffer containing 512 unit8_t type data
    
    while(fread(buffer, BLOCK_SIZE, 1, f))                      // read from f to buffer, return 1 if block_size is 512
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8)          // check if the first four bytes is JPEG signature
            && (buffer[2] == 0xff) && 
            ((buffer[3] & 0xf0) == 0xe0))
        {
            if (fw != NULL)                                     // close the file if it is opened
            {
                fclose(fw);
            }
            
            char filename[8];
            sprintf(filename, "%03d.jpg", count);
            fw = fopen(filename, "w");
            count ++;
        }
        if (fw != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, fw);
        }
    }
    
    if (fw != NULL)
    {
        fclose(fw);
    }
    
    fclose(f);
    
    return 0;
}