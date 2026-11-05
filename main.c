#include <stdio.h>

typedef struct {
    unsigned int value;
    // A child with value 0 indicates a "null" child.
    unsigned int children[2];
} TreeNode;

void treePrint(unsigned int root, const TreeNode *pool);
void treeInvert(unsigned int root, TreeNode *pool);

int main(void) {
    // Index 0 is used as a "null" index.
    TreeNode node_pool[] = {
        {.value = 666, .children = {0, 0}},
        {.value = 2, .children = {4, 0}},
        {.value = 9, .children = {0, 0}},
        {.value = 7, .children = {0, 0}},
        {.value = 4, .children = {3, 8}},
        {.value = 1, .children = {1, 7}},
        {.value = 6, .children = {2, 0}},
        {.value = 3, .children = {9, 6}},
        {.value = 8, .children = {0, 0}},
        {.value = 5, .children = {0, 0}},
    };
    unsigned int root_node = 5;

    // Initial tree
    treePrint(root_node, node_pool);

    // Inverted tree
    treeInvert(root_node, node_pool);
    treePrint(root_node, node_pool);

    return 0;
}

// Print the nodes of a binary tree ordered by depth, siblings going left to right.
void treePrint(unsigned int root, const TreeNode *pool) {
    unsigned int queue[64]   = {0};
    unsigned int queue_len   = 0;
    unsigned int queue_start = 0;

    queue[0] = root;
    queue_len = 1;

    printf("[");

    while (queue_len - queue_start > 0) {
        unsigned int search_node = queue[queue_start];
        TreeNode tree_node = pool[search_node];

        printf("%s%u", (queue_start > 0)? "," : "", tree_node.value);

        queue_start += 1;

        if (tree_node.children[0] != 0) {
            queue[queue_len] = tree_node.children[0];
            queue_len += 1;

            if (tree_node.children[1] != 0) {
                queue[queue_len] = tree_node.children[1];
                queue_len += 1;
            }
        }
    }

    printf("]\n");
}

// Inverting a binary tree, this is where the magic happens.
void treeInvert(unsigned int root, TreeNode *pool) {
    unsigned int stack[64] = {0};
    unsigned int stack_len = 0;

    stack[0] = root;
    stack_len = 1;

    while (stack_len > 0) {
        unsigned int search_node = stack[stack_len - 1];
        TreeNode *tree_node = &pool[search_node];

        stack_len -= 1;

        if (tree_node->children[0] != 0 && tree_node->children[1] != 0) {
            // XOR swap for flare and style.
            tree_node->children[0] ^= tree_node->children[1];
            tree_node->children[1] ^= tree_node->children[0];
            tree_node->children[0] ^= tree_node->children[1];

            stack[stack_len] = tree_node->children[0];
            stack_len += 1;

            stack[stack_len] = tree_node->children[1];
            stack_len += 1;
        } else if (tree_node->children[0] != 0) {
            stack[stack_len] = tree_node->children[0];
            stack_len += 1;
        }
    }
}
