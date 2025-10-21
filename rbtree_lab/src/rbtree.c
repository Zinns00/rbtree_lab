#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void)
{
  // TODO: initialize struct if needed
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));

  // sentinel(nil) 노드 생성 및 초기화
  node_t *nil_node = (node_t *)calloc(1, sizeof(node_t));
  nil_node->color = RBTREE_BLACK; // sentinel은 항상 BLACK이어야 함

  p->nil = nil_node;
  p->root = p->nil; // root 초기값도 sentinel로 설정
  return p;
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
  // 트리의 루트 노드부터 탐색 시작
  node_t *cur = t->root;

  // 현재 노드가 nil(트리의 끝)이 아닐 때까지 반복
  while (cur != t->nil)
  {
    // 현재 노드의 키 값이 찾는 값과 같으면 해당 노드를 반환
    if (key == cur->key)
    {
      return cur;
    }
    // 찾는 값이 현재 노드보다 작으면 왼쪽 자식으로 이동
    else if (key < cur->key)
    {
      cur = cur->left;
    }
    // 찾는 값이 현재 노드보다 크면 오른쪽 자식으로 이동
    else
    {
      cur = cur->right;
    }
  }
  // 값을 찾지 못한 경우 nil 노드 반환
  return t->nil;
}

node_t *rbtree_min(const rbtree *t)
{
  // TODO: implement find
  node_t *cur = t->root;

  if (cur == t->nil) // 빈 트리면 nil 반환
    return t->nil;

  while (cur->left != t->nil)
  {
    cur = cur->left;
  }
  return cur;
}

node_t *rbtree_max(const rbtree *t)
{
  // TODO: implement find
  node_t *cur = t->root;

  if (cur == t->nil)
    return t->nil;

  while (cur->right != t->nil)
  {
    cur = cur->right;
  }
  return cur;
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