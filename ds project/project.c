#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int coefficient;
    int exponent;
    struct NODE* next;
};

typedef struct NODE* node;

node getnode(node first) {
    node temp = (node)malloc(sizeof(struct NODE));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return first;
    }
    return temp;
}

node create_polynomial(node first, int coeff, int exp) {
    node newnode = getnode(first);
    newnode->coefficient = coeff;
    newnode->exponent = exp;
    newnode->next = first;
    return newnode;
}

void display_polynomial(node first) {
    node temp = first;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

node add_polynomials(node first1, node first2) {
    node first3 = NULL;
    node temp1 = first1;
    node temp2, temp3;

    while (temp1 != NULL) {
        temp2 = first2;
        while (temp2 != NULL) {
            if (temp1->exponent == temp2->exponent) {
                first3 = create_polynomial(
                    first3,
                    temp1->coefficient + temp2->coefficient,
                    temp1->exponent
                );
                break;
            }
            temp2 = temp2->next;
        }

        if (first3 == NULL || first3->exponent != temp1->exponent) {
            first3 = create_polynomial(first3, temp1->coefficient, temp1->exponent);
        }
        temp1 = temp1->next;
    }

    temp2 = first2;
    while (temp2 != NULL) {
        int isThere = 0;
        temp3 = first3;

        while (temp3 != NULL) {
            if (temp2->exponent == temp3->exponent) {
                isThere = 1;
                break;
            }
            temp3 = temp3->next;
        }

        if (!isThere) {
            first3 = create_polynomial(first3, temp2->coefficient, temp2->exponent);
        }
        temp2 = temp2->next;
    }
    return first3;
}

node sub_polynomials(node first1, node first2) {
    node first3 = NULL;
    node temp1 = first1;
    node temp2, temp3;

    while (temp1 != NULL) {
        temp2 = first2;
        while (temp2 != NULL) {
            if (temp1->exponent == temp2->exponent) {
                first3 = create_polynomial(
                    first3,
                    temp1->coefficient - temp2->coefficient,
                    temp1->exponent
                );
                break;
            }
            temp2 = temp2->next;
        }

        if (first3 == NULL || first3->exponent != temp1->exponent) {
            first3 = create_polynomial(first3, temp1->coefficient, temp1->exponent);
        }
        temp1 = temp1->next;
    }

    temp2 = first2;
    while (temp2 != NULL) {
        int isThere = 0;
        temp3 = first3;

        while (temp3 != NULL) {
            if (temp2->exponent == temp3->exponent) {
                isThere = 1;
                break;
            }
            temp3 = temp3->next;
        }

        if (!isThere) {
            first3 = create_polynomial(first3, temp2->coefficient, temp2->exponent);
        }
        temp2 = temp2->next;
    }
    return first3;
}

node mul_polynomials(node first1, node first2) {
    node first3 = NULL;

    for (node t1 = first1; t1 != NULL; t1 = t1->next) {
        for (node t2 = first2; t2 != NULL; t2 = t2->next) {

            int coeff = t1->coefficient * t2->coefficient;
            int exp   = t1->exponent + t2->exponent;

            node temp = first3;
            int found = 0;

            while (temp != NULL) {
                if (temp->exponent == exp) {
                    temp->coefficient += coeff;
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if (!found) {
                first3 = create_polynomial(first3, coeff, exp);
            }
        }
    }
    return first3;
}

int main() {
    int n, coeff, exp;
    node first1 = NULL, first2 = NULL, first3 = NULL;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Coefficient %d:",i+1);
        scanf("%d", &coeff);
        printf("Exponent %d:",i+1);
        scanf("%d", &exp);
        first1 = create_polynomial(first1, coeff, exp);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Coefficient %d: ",i+1);
        scanf("%d", &coeff);
        printf("Exponent %d: ",i+1);
        scanf("%d", &exp);
        first2 = create_polynomial(first2, coeff, exp);
    }

    printf("\nPolynomial 1:\n");
    display_polynomial(first1);

    printf("Polynomial 2:\n");
    display_polynomial(first2);

    first3 = add_polynomials(first1, first2);
    printf("SUM:\n");
    display_polynomial(first3);

    first3 = sub_polynomials(first1, first2);
    printf("SUB:\n");
    display_polynomial(first3);

    first3 = mul_polynomials(first1, first2);
    printf("MUL:\n");
    display_polynomial(first3);

    return 0;
}
