#include <stdio.h>

typedef enum Operation {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} optype;

void get_parameters(double *a, optype *op, double *b) {
	char operatorchar;
	scanf("%lf %c %lf", a, &operatorchar, b);
    switch (operatorchar) {
            case '+':
                *op = ADDITION;
                break;
            case '-':
                *op = SUBTRACTION;
                break;
            case '*':
                *op = MULTIPLICATION;
                break;
            case '/':
                *op = DIVISION;
                break;
            default:
                printf("Invalid operation.\n");
                break;
        }
}

void print_result(double a, optype op, double b) {
    switch(op) {
        case ADDITION:
            printf("Result:%.2lf + %.2lf = %.2lf\n", a, b, a + b);
            break;
        case SUBTRACTION:
            printf("Result:%.2lf - %.2lf = %.2lf\n", a, b, a - b);
            break;
        case MULTIPLICATION:
            printf("Result:%.2lf * %.2lf = %.2lf\n", a, b, a * b);
            break;
        case DIVISION:
            if (b != 0)
                printf("Result:%.2lf / %.2lf = %.2lf\n", a, b, a / b);
            else
                printf("Cannot divide by zero.\n");
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    int i;
    double num1, num2;
    char operatorchar;
    optype op;
   	printf("Type an arithmetic question(e.g., 1 + 2):");
        get_parameters(&num1,&op,&num2);
    	print_result(num1,op,num2);
    
    return 0;
}

