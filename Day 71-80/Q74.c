/*Problem Statement: Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char names[100][20];
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }
    
    char winner[20] = "zzzzzzzzzzzzzzzzzzz";
    int max_votes = -1;
    
    for(int i = 0; i < n; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
            }
        }
        if(count > max_votes || (count == max_votes && strcmp(names[i], winner) < 0)) {
            max_votes = count;
            strcpy(winner, names[i]);
        }
    }
    
    printf("%s %d\n", winner, max_votes);
    return 0;
}
