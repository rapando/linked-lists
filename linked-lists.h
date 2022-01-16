
struct node {
    int val;
    struct node *next;
};

void traverse(struct node *head);
void addNode(struct node *n, int val);
void search(struct node *n, int val);
void replace(struct node *n, int position, int newValue);
void deleteNode(struct node *n, int position);
void insert(struct node *n, int position, int val);