/*Problem Statement: Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    
    int seen[26] = {0};
    int first[26];
    
    for(int i = 0; i < 26; i++) {
        first[i] = -1;
    }
    
    char ans = '-';
    int min_idx = 10000;
    
    for(int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        
        if(seen[idx] == 0) {
            seen[idx] = 1;
            first[idx] = i;
        } else {
            if(first[idx] != -1 && i < min_idx) {
                min_idx = i;
                ans = s[i];
            }
        }
    }
    
    if(ans == '-') {
        printf("-1\n");
    } else {
        printf("%c\n", ans);
    }
    
    return 0;
}
