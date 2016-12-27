#ifndef rbt_H_
#define rbt_H_

#define IS_BLACK(x) ((NULL == (x)) || (BLACK == (x)->colour))/*in h file?*/
#define IS_RED(x) ((NULL != (x)) && (RED == (x)->colour))

typedef struct rbt_node *rbt;
extern rbt rbt_delete(rbt b, char *str);
extern rbt rbt_free(rbt b);
extern void rbt_inorder(rbt b, void f(char *str));
extern rbt rbt_insert(rbt b, char *str);
extern rbt rbt_new();
extern void rbt_preorder(rbt b, void f(char *str));
extern int rbt_search(rbt b, char *str);
#endif
