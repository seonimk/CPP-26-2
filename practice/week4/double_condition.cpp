#include <stdio.h>

int main() {
    int num1, num2;

    printf("두 양수를 입력하세요 : ");
    scanf_s("%d %d",&num1, &num2);

    if (num1 > 0) {
        if (num2 > 0) {
            printf("%d %d 두 숫자 모두 양수입나다.\n", &num1, &num2);
        }
        else {
            printf("%d 만 양수입니다.\n", &num1);
        }
    }
    else {
        printf("%d 는 0이거나 음수입니다.\n", &num1);
    }
    return 0;
}