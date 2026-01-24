#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fptr;
    struct Student{
     char idNum[10];
     char answer[4];
    }student[5];
    int i,j;
    int correctKey[4] = {1, 4, 2, 3};
     fptr = fopen("answers.dat", "w");
     if (fptr == NULL) {
        printf("File openning error....!");
        return -1;
    }
    for (i = 0; i < 5; i++) {
        printf("Enter Student %d ID Number (ITXXXXXX): ", i + 1);
        scanf("%s", student[i].idNum);
        fprintf(fptr, "%s\t\t", student[i].idNum);
    for (j = 0; j < 4; ) {
           int tempAns;
            printf("Enter Question %d answer (1-5): ", j + 1);
            scanf("%d", &tempAns);

            if (tempAns >= 1 && tempAns <= 5) {
                student[i].answer[j] = tempAns;
                fprintf(fptr, "%d ", student[i].answer[j]);
                j++;
            } else {
                printf("Invalid choice! Should be 1-5.\n");
            }
        }
    fprintf(fptr, "\n");
    printf("\n");
  }
  fclose(fptr);
   printf("--------------------------------------------\n");
    printf("Student ID\tNumber of Correct Answers\n");
    printf("--------------------------------------------\n");
    fptr = fopen("answers.dat", "r");
    if (fptr == NULL) {
        printf("Error reading file!");
        return -1;
    }
    char tempID[10];
    int ans1, ans2, ans3, ans4;
    while (fscanf(fptr, "%s %d %d %d %d", tempID, &ans1, &ans2, &ans3, &ans4) != EOF) {
        int correctCount = 0;
        if (ans1 == correctKey[0]) correctCount++;
        if (ans2 == correctKey[1]) correctCount++;
        if (ans3 == correctKey[2]) correctCount++;
        if (ans4 == correctKey[3]) correctCount++;
        printf("%s\t\t%d\n", tempID, correctCount);
    }
    fclose(fptr);
  return 0;
}
