#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *wptr;
    struct Student{
     char idNum[8];
     char answer[4];
    }student[5];
    int i,j;
     wptr = fopen("answers.dat", "w");
     if (wptr == NULL) {
        printf("File openning error....!");
        return -1;
    }
    for (i = 0; i < 5; i++) {
        printf("Enter Student %d ID Number : ", i + 1);
        scanf("%s", student[i].idNum);
        fprintf(wptr, "%s\t\t", student[i].idNum);
    for (j = 0; j < 4; ) {
            printf("Enter Question %d answer : ", j + 1);
            scanf("%d", &student[i].answer[j]);
        if((student[i].answer[j] <= 5) && (student[i].answer[j] >= 1)){
            fprintf(wptr, "%d\t", student[i].answer[j]);
            j++;
        }
        else{
            printf("Invalid choice, choice should be 1,2,3,4 or 5 : ");
        }
        printf("\n");
    }
    fprintf(wptr, "\n");
  }
  fclose(wptr);
  return 0;
}
