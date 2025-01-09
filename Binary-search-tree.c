#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

void createNode(struct node **newNode) {
    int item;
    printf("\nEnter the data\n");
    scanf("%d", &item);
    *newNode = (struct node *)malloc(sizeof(struct node));
    (*newNode)->data = item;
    (*newNode)->left = (*newNode)->right = NULL;
}

void searchAndInsert(struct node *ptr, struct node *newNode) {
    if (newNode->data > ptr->data) {
        if (ptr->right != NULL)
            searchAndInsert(ptr->right, newNode);
        else
            ptr->right = newNode;
    } else if (newNode->data < ptr->data) {
        if (ptr->left != NULL)
            searchAndInsert(ptr->left, newNode);
        else
            ptr->left = newNode;
    }
}

void insert() {
    struct node *newNode;
    createNode(&newNode);
    if (root == NULL)
        root = newNode;
    else
        searchAndInsert(root, newNode);
}

int smallestLeftNode(struct node *ptr) {
    while (ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr->data;
}

struct node* deleteNode(struct node *root, int item) {
    if (root == NULL) {
        printf("\nItem not found\n");
        return root;
    }
    
    if (item < root->data) {
        root->left = deleteNode(root->left, item);
    } else if (item > root->data) {
        root->right = deleteNode(root->right, item);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;  // Return the right child
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;  // Return the left child
        }

        // Node with two children
        root->data = smallestLeftNode(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}

void deleteNodeMenu() {
    int item;
    if (root == NULL) {
        printf("\nTree - empty\n");
        return;
    }
    printf("\nEnter the item to delete\n");
    scanf("%d", &item);
    root = deleteNode(root, item);
}

void inorder(struct node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr) {
    if (ptr != NULL) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

void display(struct node *ptr) {
    if (ptr == NULL) {
        printf("\nTree - empty");
    } else {
        printf("\nInorder traversal:\n");
        inorder(ptr);
        printf("\n\nPreorder traversal:\n");
        preorder(ptr);
        printf("\n\nPostorder traversal:\n");
        postorder(ptr);
    }
    printf("\n");
}

int search(struct node *ptr, int item) {
    if (ptr == NULL) {
        return 0; // not found
    }
    if (ptr->data == item) {
        return 1; // found
    }
    if (item < ptr->data) {
        return search(ptr->left, item); // left search
    } else {
        return search(ptr->right, item); // right search 
    }
}

void searchMenu() {
    int item;
    printf("\nEnter the value to search\n");
    scanf("%d", &item);
    if (search(root, item)) {
        printf("\nItem %d found \n", item);
    } else {
        printf("\nItem %d not found \n", item);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert node\n2. Display\n3. Delete node\n4. Search\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                display(root);
                break;

            case 3:
                deleteNodeMenu();
                break;

            case 4:
                searchMenu();
                break;

            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
}
