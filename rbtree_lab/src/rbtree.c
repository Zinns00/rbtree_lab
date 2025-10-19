#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void)
{
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));

  // sentinel(nil) 노드 생성 및 초기화
  node_t *nil_node = (node_t *)calloc(1, sizeof(node_t));
  nil_node->color = RBTREE_BLACK; // sentinel은 항상 BLACK이어야 함

  p->nil = nil_node;
  p->root = p->nil; // root 초기값도 sentinel로 설정
  return p;
  // TODO: initialize struct if needed
}

void delete_rbtree(rbtree *t)
{
  // TODO: reclaim the tree nodes's memory
  free(t);
}

node_t *rbtree_insert(rbtree *t, const key_t key)
{
  // TODO: implement insert
  node_t *z = (node_t *)calloc(1, sizeof(node_t)); // 새 노드 생성
  z->key = key;
  z->left = z->right = t->nil;
  z->color = RBTREE_RED;

  node_t *root = t->root;  // 삽입 위치의 부모
  node_t *parent = t->nil; // 탐색 시작점

  while (root != t->nil)
  {
    parent = root;
    if (z->key < root->key)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }

  // 부모 설정
  z->parent = parent;

  if (parent == t->nil)
  {
    t->root = z;
  }
  else if (z->key < parent->key)
  {
    parent->left = z;
  }
  else
  {
    parent->right = z;
  }

  return z;
}

node_t *rbtree_find(const rbtree *t, const key_t key)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_min(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t)
{
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *p)
{
  // TODO: implement erase
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n)
{
  // TODO: implement to_array
  return 0;
}
