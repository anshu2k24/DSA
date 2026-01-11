#include <stdio.h>

struct NODE {
    int coefficient;
    int exponent;
    NODE* next;
};

typedef NODE* node;

node getnode(node first) {
    node temp = (node) malloc(sizeof(struct NODE));
    if (temp == NULL) {
        printf( "Memory not allocated\n");
        return first;
    }
    return temp;
}

node create_polynomial(node first,int coeff,int exp) {
        node newnode = getnode(first);
        newnode->coefficient = coeff;
        newnode->exponent = exp;
        newnode->next = first;
        return newnode;
}

void display_polynomial(node first) {
    node temp = first;
    while (temp != NULL) {
        printf( temp->coefficient << "x^" << temp->exponent;
        temp = temp->next;
        if (temp != NULL) {
            printf( " + ";
        }
    }
    printf( endl;
}

node add_polynomials(node first1,node first2){
    node first3 = NULL;
    node temp1 = first1;
    node temp2 = first2;
    node temp3 = first3;

    while(temp1 != NULL){
        temp2 = first2;
        while(temp2 != NULL){
            if(temp1->exponent == temp2->exponent){
                first3 = create_polynomial(first3,temp1->coefficient+temp2->coefficient,temp1->exponent);
                break;
            }
            temp2 = temp2->next;
        }
        if(first3->exponent != temp1->exponent){
            first3 = create_polynomial(first3,temp1->coefficient,temp1->exponent);
        }
        temp1 = temp1->next;
    }
    int isThere = 0;
    temp2 = first2;
    while(temp2 != NULL){
        isThere = 0;
        temp3 = first3;
        while(temp3!=NULL){
            if(temp2->exponent == temp3->exponent){
                isThere = 1;
                break;
            }
            temp3 = temp3->next;
        }
        if(!isThere){
            first3 = create_polynomial(first3,temp2->coefficient,temp2->exponent);
        }
        temp2 = temp2->next;
    }
    return first3;
}

node sub_polynomials(node first1,node first2){
    node first3 = NULL;
    node temp1 = first1;
    node temp2 = first2;
    node temp3 = first3;

    while(temp1 != NULL){
        temp2 = first2;
        while(temp2 != NULL){
            if(temp1->exponent == temp2->exponent){
                first3 = create_polynomial(first3,temp1->coefficient-temp2->coefficient,temp1->exponent);
                break;
            }
            temp2 = temp2->next;
        }
        if(first3->exponent != temp1->exponent){
            first3 = create_polynomial(first3,temp1->coefficient,temp1->exponent);
        }
        temp1 = temp1->next;
    }
    int isThere = 0;
    temp2 = first2;
    while(temp2 != NULL){
        isThere = 0;
        temp3 = first3;
        while(temp3!=NULL){
            if(temp2->exponent == temp3->exponent){
                isThere = 1;
                break;
            }
            temp3 = temp3->next;
        }
        if(!isThere){
            first3 = create_polynomial(first3,temp2->coefficient,temp2->exponent);
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

    //Initialising first pointers
    node first1 = NULL;
    node first2 = NULL;
    node first3 = NULL;

    //Polynomial 1
    printf( "Enter the number of terms in the polynomial 1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        printf( "Enter coefficient for term " << (i + 1) << ": ";
        cin >> coeff ;
        printf( "Enter exponent for term " << (i + 1) << ": ";
        cin >> exp;
        first1 = create_polynomial(first1, coeff, exp);
    }

    //Poynomial 2
    printf( "Enter the number of terms in the polynomial 2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        printf( "Enter coefficient for term " << (i + 1) << ": ";
        cin >> coeff ;
        printf( "Enter exponent for term " << (i + 1) << ": ";
        cin >> exp;
        first2 = create_polynomial(first2, coeff, exp);
    }

    //diplaying polynomials
    printf( "Polynomial 1:\n";
    display_polynomial(first1);

    printf( "Polynomial 2:\n";
    display_polynomial(first2);

    //calling add_polynomials
    first3=add_polynomials(first1,first2);

    printf( "Result Polynomial SUM:\n";
    display_polynomial(first3);

    //calling sub_polynomials
    first3=sub_polynomials(first1,first2);

    printf( "Result Polynomial SUB:\n";
    display_polynomial(first3);

    //calling mul_polynomials
    first3=mul_polynomials(first1,first2);

    printf( "Result Polynomial MUL:\n";
    display_polynomial(first3);
    
    return 0;
}