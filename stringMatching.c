#include<stdio.h>
#include<string.h>
void stringMatching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int j;
    for(int i=0;i<=n-m;i++) {
        for(j=0;j<m;j++) {
            if(text[i+j]!=pattern[j]) {
                break;
            }
        }
        if(j==m) {
            printf("Pattern match found at index %d\n",i);
        }
    }
}
int main() {
    char text[] = "AABACADACAABAABA";
    char pattern[] = "AABA";
    stringMatching(text,pattern);
    return 0;
}
