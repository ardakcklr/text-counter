#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *file;
    
    int totalWord=0;
    int totalNumber=0;
    int totalPunctuation=0;
    int totalUpper=0;
    int totalLower=0;
    
    char currentCharacter;

    
    if((file=fopen("a.txt","r"))==NULL){
        printf("File does not exist or can not be found !");
    }
    
    else{
    
    while (!feof(file)){
        
        currentCharacter = fgetc(file);
        
        if(isspace(currentCharacter)){
            totalWord++;
        }
        else if(ispunct(currentCharacter)){
            totalPunctuation++;
        }
        else if(isalnum(currentCharacter)){
            if(isdigit(currentCharacter)){
                totalNumber++;
            }
            else if(isalpha(currentCharacter)){
                if(islower(currentCharacter)){
                    totalLower++;
                }
                else if(isupper(currentCharacter)){
                    totalUpper++;
                }
            }
        }
    }
    
    fclose(file);
    
    totalWord++;
    
    printf("Total number of words in the file is: %d\n",totalWord);
    printf("Total number of punctuation marks in the file is: %d\n",totalPunctuation);
    printf("Total number of numbers in the file is: %d\n",totalNumber);
    printf("Total number of lower case letters in the file is: %d\n",totalLower);
    printf("Total number of upper case letters in the file is: %d\n",totalUpper);
    
    int value[5]= {totalWord,totalPunctuation,totalNumber,totalLower,totalUpper};
    char element[5][1000]= {"TWords","PunctM","Number","LowerC","UpperC"};
    int i;
    int j;
    
    printf("\n");
    printf("%s%13s%17s\n", "Element", "Value", "Histogram");
    printf("\n");
    
   
    for(int i=0; i<5; i++){
        printf("%5s%14d        ",element[i],value[i]);
        for (int j=1; j<= value[i]; j++){
            printf("%c",'*');
        }
        printf("\n");
    }
    
    return 0;
}
}
