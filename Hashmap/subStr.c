#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestSubstringWithKDistinct(char *s, int K) {
    int n = strlen(s);
    if (K == 0) return -1;
    
    int freq[256] = {0};
    
    int left = 0, maxLength = -1, distinctCount = 0;
    
    for (int right = 0; right < n; right++) {
        if (freq[s[right]] == 0) {
            distinctCount++;
        }
        freq[s[right]]++;
        
        while (distinctCount > K) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                distinctCount--;
            }
            left++;
        }
        
        if (distinctCount == K) {
            maxLength = (maxLength > right - left + 1) ? maxLength : right - left + 1;
        }
    }
    
    return maxLength;
}

int main() {
    char s[] = "ecebababeeeebee";
    int K = 2;
    
    int result = longestSubstringWithKDistinct(s, K);
    
    printf("Length of longest substring with exactly %d distinct characters: %d\n", K, result);
    
    return 0;
}
