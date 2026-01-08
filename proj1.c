#include<stdio.h>
int main(){
    int testMarks[10];
    for(int i=0; i<10; i++){
        testMarks[i]=-1;
    }
    for(int i=0;i<10;i++){
        printf("Input marks %d: ",(i+1));
        scanf("%d", &testMarks[i]);
        if(testMarks[i]>100 || testMarks[i]<0){
            printf("Invalid marks. Please re-enter.\n");
            printf("Input marks %d: ",(i+1));
            scanf("%d", &testMarks[i]);
        }
    }
    float sum=0.0;
    for(int i=0;i<10;i++){
        sum=sum+testMarks[i];
    }
    float avg=sum/10.0;
    printf("Passed marks: ");
    for(int i=0;i<10;i++){
        if(testMarks[i]>avg){
            printf("%d ",testMarks[i]);
        }    
    }
    return 0;
}