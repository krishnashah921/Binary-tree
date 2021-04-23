//postfix expression
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
char data; 
struct node *lptr;
struct node *rptr; 
}; 
char* add(struct node** p, char* a) 
{ 
  
    
    if (*a == '\0') 
        return '\0'; 
  
    while (1) { 
        char* q = "null"; 
        if (*p == NULL) { 
  
            struct node* nn = (struct node*)malloc(sizeof(struct node)); 
            nn->data = *a; 
            nn->lptr= NULL; 
            nn->rptr = NULL; 
            *p = nn; 
        } 
        else { 
  
            
            if (*a >= 'a' && *a <= 'z') { 
                return a; 
            } 
  
            
            q = add(&(*p)->lptr, a + 1); 
  
            
            q = add(&(*p)->rptr, q + 1); 
  
            return q; 
        } 
    } 
} 
  

void postr(struct node* p) 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        postr(p->lptr); 
        postr(p->rptr); 
        printf("%c ", p->data); 
    } 
} 
  
int main() 
{ 
    struct node* s = NULL; 
    char a[] = "*+ab-cd"; 
    add(&s, a);  
    printf("The Postfix expression is:\n "); 
    postr(s); 
    return 0; 
}
