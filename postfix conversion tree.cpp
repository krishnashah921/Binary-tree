#include<stdio.h>
#include<stdlib.h>
struct n {
   char d;
   n *l;
   n *r;
};
char pf[50];
int top = -1;
n *a[50];
int r(char inputch) {
   if (inputch == '+' || inputch == '-' || inputch == '*' || inputch== '/')
      return (-1);
   else if (inputch >= 'A' || inputch <= 'Z')
      return (1);
   else if (inputch >= 'a' || inputch <= 'z')
      return (1);
   else
      return (-100);
}
void push(n *tree) {
   top++;
   a[top] = tree;
}
n *pop() {
   top--;
   return (a[top + 1]);
}
void construct_expression_tree(char *suffix) {
   char s;
   n *newl, *p1, *p2;
   int flag;
   s = suffix[0];
   for (int i = 1; s != 0; i++) {
      flag = r(s);
      if (flag == 1) {
         newl = (struct n*)malloc(sizeof(struct n));
         newl->d = s;
         newl->l = NULL;
         newl->r = NULL;
         push(newl);
      } else {
         p1 = pop();
         p2 = pop();
         newl = (struct n*)malloc(sizeof(struct n));
         newl->d = s;
         newl->l = p2;
         newl->r = p1;
         push(newl);
      }
      s = suffix[i];
   }
}
void postOrder(n *tree) {
   if (tree != NULL) {
      postOrder(tree->l);
      postOrder(tree->r);
     printf("%c",tree->d);
   }
}
int main() {
   printf( "Enter Postfix Expression : ");
   scanf("%s",pf);
   construct_expression_tree(pf);
   postOrder(a[0]);
   return 0;
}
