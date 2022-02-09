#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int value;         // this is the value the node stores
    struct node *next; // this is the node the current node points to. this is how the nodes link
} node;

node *head=NULL;
node *tail=NULL;

int createNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->value = val;
    newNode->next = NULL;
    if (head==NULL){
        head = tail = newNode;//! in the case where the list is empty , the start and end is the same ...
    }else{
        tail->next = newNode;
        tail = tail->next;
        //! in this case the tail is only updated keeping head constant ....
    };
    return 0;
};

int printList(){
    node *temp = head;
    while (temp!=NULL)
    {
        printf(" %d-> " ,temp->value);
        temp = temp->next;
    }
    printf("now");
    return 0;
};

int calcy(){

        printf("\nbeginning the code\n");
        char operator;
        double first, second;
        size_t result;
        // printf("Enter an operator (+, -, *,): \n");
        printf("Enter two operands:  and the operator like this \n->1 \n->+ \n->2\n");
        scanf("%lf %c %lf", &first,&operator ,&second);
        // sleep(3);
        // printf("enter the operator ");
        // scanf_s("%c", &operator,1);
        switch (operator)
        {
        case '+':
            printf("%.1lf + %.1lf = %.1lf", first, second, first + second);
            result = first + second;
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf", first, second, first - second);
            result = first - second;
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf", first, second, first * second);
            result = first * second;
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf", first, second, first / second);
            result = first / second;
            break;
        // operator doesn't match any case constant
        default:
            printf("Error! operator is not correct");
        }
        createNode(result);
        return 0;
};

int main(){
    while(1)
    {
    calcy();
    printf("\n");
    printList();
    };
    return 0;
};
