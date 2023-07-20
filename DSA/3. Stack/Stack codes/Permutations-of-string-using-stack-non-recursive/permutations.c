#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

void push(stack *s, char *data) {
    node *n = (node *)malloc(sizeof(node));
    n->data = (char *)malloc(strlen(data)+1);
    strcpy(n->data, data);
    n->next = s->top;
    s->top = n;
}

char *pop(stack *s) {
    if(s->top == NULL) {
        return NULL;
    }
    node *n = s->top;
    s->top = n->next;
    char *data = n->data;
    free(n);
    return data;
}

void pushPermuts(char *word, stack *permuteStack) {
    int marker = strchr(word, '+') - word;
    char *prefix = (char *)malloc(marker+1);
    strncpy(prefix, word, marker);
    prefix[marker] = '\0';
    char *suffix = word + marker + 1;
    for(int i=0; i<strlen(suffix); i++) {
        char *newWord = (char *)malloc(strlen(prefix)+strlen(suffix)+2);
        strcpy(newWord, prefix);
        newWord[strlen(prefix)] = suffix[i];
        newWord[strlen(prefix)+1] = '+';
        newWord[strlen(prefix)+2] = '\0';
        strncat(newWord, suffix, i);
        strcat(newWord, suffix+i+1);
        push(permuteStack, newWord);
    }
}

void printPermutations(char *s) {
    stack *permuteStack = (stack *)malloc(sizeof(stack));
    permuteStack->top = NULL;
    char *word = (char *)malloc(strlen(s)+2);
    strcpy(word, "+");
    strcat(word, s);
    push(permuteStack, word);
    while((word = pop(permuteStack)) != NULL) {
        if(word[strlen(word)-1] == '+') {
            printf("%s\b \n", word);
        }
        else {
            pushPermuts(word, permuteStack);
        }
    }
}

int main() {
    printPermutations("12345");
    return 0;
}