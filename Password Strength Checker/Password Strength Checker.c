#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int score = 0;
printf("===========================================\n");
printf("    NeoLock: Password Strength Checker   \n");
printf("===========================================\n\n");

    printf(" Password Strength Checker \n");
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    // Check length
    if (length >= 8) {
        printf(" Strong length (8+ characters)\n");
        score += 2;
    } else {
        printf(" Too short (less than 8 characters)\n");
    }

    // Flags
    int hasSpecial = 0, hasDigit = 0, hasUpper = 0;

    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) hasSpecial = 1;
        if (isdigit(password[i])) hasDigit = 1;
        if (isupper(password[i])) hasUpper = 1;
    }

    // Special characters
    if (hasSpecial) {
        printf(" Contains special character(s)\n");
        score += 2;
    } else {
        printf(" No special characters\n");
    }

    // Numbers
    if (hasDigit) {
        printf(" Contains number(s)\n");
        score += 2;
    } else {
        printf(" No numbers\n");
    }

    // Uppercase letters
    if (hasUpper) {
        printf(" Contains uppercase letter(s)\n");
        score += 2;
    } else {
        printf(" No uppercase letters\n");
    }

    // Final verdict
    printf("\n Password Strength Score: %d/8\n", score);
    if (score >= 6) {
        printf("(^_^) Great! Your password is strong.\n");
    } else {
        printf("(-_-) Weak password. Try adding more variety!\n");
    }

    return 0;
}
