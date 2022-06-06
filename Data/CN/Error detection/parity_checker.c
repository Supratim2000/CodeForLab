#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void printarr(int arr[],int n){
    for(int i=0; i<n; i++){
        printf("%d",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    int arr[SIZE],i = 0;
    while(n>0){
        arr[i] = n%2;
        n =n/ 2;
        i++;
    }
    int bin[i+1],cnt = 0;
    for(int j=i-1; j>=0; j--){
        printf("%d",arr[j]);
        bin[i-j-1] = arr[j];
        if(arr[j] == 1){
            cnt++;
        }
    }
    int choice;
    printf("\nEnter the choice : ");
    printf("\n1.Even parity bit");
    printf("\n2.Odd parity bit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            if(cnt % 2 == 0){
                bin[i] = 0;
            }
            else bin[i] = 1;
            break;
        case 2:
            if(cnt%2 == 0){
                bin[i] = 1;
            }
            else bin[i] = 0;
            break;
         default:
            printf("Error! operator is not correct");
    }
    for(int k=0;k<i+1;k++){
        printf("%d",bin[k]);
    }
}