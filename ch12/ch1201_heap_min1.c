/* Data Structures Using C, 2nd, Reema Thareja
Chapter 12. Heaps

# min heap
http://www.martinbroadhurst.com/min-heap-in-c.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // For memcpy and memmove
#define START_SIZE 4

// for dynamic array
struct dynarray {
  void **buffer;
  unsigned int size;
  unsigned int count;
};

typedef struct dynarray dynarray;
typedef void (*dynarray_forfn)(void *);

// for min heap
struct entry {
  void *item;
  unsigned int value;
};
typedef struct entry entry;

struct minheap {
  dynarray *entries;
};
typedef struct minheap minheap;

typedef void (*minheap_forfn)(void *);

dynarray *dynarray_create(unsigned int startsize);
void dynarray_empty(dynarray *array);
void dynarray_delete(dynarray *array);
void dynarray_add_tail(dynarray *array, void *data);
void dynarray_add_head(dynarray *array, void *data);
void *dynarray_remove_tail(dynarray *array);
void *dynarray_remove_head(dynarray *array);
void dynarray_insert(dynarray *array, unsigned int pos, void *data);
void *dynarray_remove(dynarray *array, unsigned int pos);
void *dynarray_get(const dynarray *array, unsigned int pos);
void *dynarray_set(dynarray *array, unsigned int pos, void *data);
void dynarray_for_each(const dynarray *array, dynarray_forfn fun);
unsigned int dynarray_get_count(const dynarray *array);
void dynarray_set_size(dynarray *array, unsigned int size);

minheap *minheap_create(void);
void minheap_delete(minheap *heap);
void minheap_add(minheap *heap, void *item, unsigned int value);
void *minheap_remove_min(minheap *heap);
void minheap_for_each(const minheap *heap, minheap_forfn fun);
unsigned int minheap_get_count(const minheap *heap);

int main(void) {
  minheap *heap = minheap_create();
  unsigned int numbers[10];
  unsigned int i;
  for (i = 0; i < 10; i++) {
    numbers[i] = i;
    minheap_add(heap, &(numbers[i]), i);
  }
  printf("Count is %u\n", minheap_get_count(heap));
  for (i = 0; i < 10; i++) {
    const int *e = minheap_remove_min(heap);
    if (e) {
      printf("%d\n", *e);
    }
  }
  printf("Count is now %u\n", minheap_get_count(heap));
  minheap_delete(heap);

  /*
  dynarray *array = dynarray_create(0); //No preferred size
  unsigned int i;
  void *data;
  char *elements[] = {"A", "B", "C", "D", "E", "F"};
  const unsigned int n = sizeof(elements) / sizeof(const char *);

  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      dynarray_add_head(array, elements[i]);
    } else {
      dynarray_add_tail(array, elements[i]);
    }
  }

  //Same as dynarray_addhead
  dynarray_insert(array, 0, "X");
  dynarray_insert(array, dynarray_get_count(array) / 2, "Y");
                   //Insert in the middle
  dynarray_insert(array, dynarray_get_count(array), "Z");
                   //Same as dynarray_add_tail

  dynarray_set(array, dynarray_get_count(array) / 2, "P");
  dynarray_set(array, dynarray_get_count(array), "Q");
               //Same as dynarray_add_tail

  for (i = 0; i < dynarray_get_count(array); i++) {
    printf("%d: %s\n", i, (const char *)dynarray_get(array, i));
  }
  putchar('\n');

  for (i = 0; dynarray_get_count(array); i++) {
    const unsigned int action = i % 3;
    if (action == 0) {
      data = dynarray_remove_head(array);
    } else if (action == 1) {
      data = dynarray_remove_tail(array);
    } else {
      data = dynarray_remove(array, dynarray_get_count(array) / 2);
    }
    printf("Removed: %s\n", (const char *)data);
  }

  dynarray_delete(array);
  */

  return 0;
}

dynarray *dynarray_create(unsigned int size) {
  dynarray *array = malloc(sizeof(dynarray));
  if (array != NULL) {
    if (size) {
      array->buffer = malloc(size * sizeof(void *));
      if (array->buffer) {
        array->size = size;
      } else {
        free(array);
        array = NULL;
      }
    } else {
      array->buffer = NULL;
      array->size = 0;
    }
    array->count = 0;
  }
  return array;
}

void dynarray_empty(dynarray *array) { array->count = 0; }

void dynarray_delete(dynarray *array) {
  if (array) {
    free(array->buffer);
    free(array);
  }
}

void dynarray_add_tail(dynarray *array, void *data) {
  if (array->count == array->size) {
    // No more space//
    if (array->buffer != NULL) {
      void **buffer = realloc(array->buffer, array->size * 2 * sizeof(void *));
      array->buffer = buffer;
      array->size *= 2;
    } else {
      array->buffer = malloc(START_SIZE * sizeof(void *));
      array->size = START_SIZE;
    }
  }
  if (array->buffer != NULL) {
    array->buffer[array->count] = data;
    array->count++;
  }
}

void dynarray_add_head(dynarray *array, void *data) {
  if (array->count == array->size) {
    // No more space//
    if (array->buffer != NULL) {
      void **temp = malloc(array->size * 2 * sizeof(void *));
      if (temp) {
        /* Copy the elements one space to the right */
        memcpy(temp + 1, array->buffer, array->count * sizeof(void *));
        free(array->buffer);
        array->buffer = temp;
        array->size *= 2;
      }
    } else {
      array->buffer = malloc(START_SIZE * sizeof(void *));
      if (array->buffer) {
        array->size = START_SIZE;
      }
    }
  } else {
    /* Move the elements one space to the right */
    memmove(array->buffer + 1, array->buffer, array->count * sizeof(void *));
  }
  if (array->buffer != NULL) {
    array->buffer[0] = data;
    array->count++;
  }
}

void *dynarray_remove_tail(dynarray *array) {
  void *data = NULL;
  if (array->count > 0) {
    data = array->buffer[array->count - 1];
    array->count--;
  }
  return data;
}

void *dynarray_remove_head(dynarray *array) {
  void *data = NULL;
  if (array->count > 0) {
    data = array->buffer[0];
    /* Move the elements one space to the left */
    memmove(array->buffer, array->buffer + 1,
            (array->count - 1) * sizeof(void *));
    array->count--;
  }
  return data;
}

void dynarray_insert(dynarray *array, unsigned int pos, void *data) {
  if (pos == 0) {
    dynarray_add_head(array, data);
  } else if (pos == array->count) {
    dynarray_add_tail(array, data);
  } else if (pos < array->count) {
    unsigned int i;
    if (array->count == array->size) {
      /* Reallocate the buffer and copy, leaving a space */
      void **temp = malloc(array->size * 2 * sizeof(void *));
      if (temp) {
        memcpy(temp, array->buffer, pos * sizeof(void *));
        memcpy(temp + pos + 1, array->buffer + pos,
               (array->count - pos) * sizeof(void *));
        free(array->buffer);
        array->buffer = temp;
        array->size *= 2;
      }
    } else {
      /* Move the elements after to the right */
      memmove(array->buffer + pos + 1, array->buffer + pos,
              (array->count - pos) * sizeof(void *));
    }
    array->buffer[pos] = data;
    array->count++;
  }
}

void *dynarray_remove(dynarray *array, unsigned int pos) {
  void *data;
  if (array->count < pos + 1) {
    data = NULL;
  } else if (pos == 0) {
    data = dynarray_remove_head(array);
  } else if (pos == array->count - 1) {
    data = dynarray_remove_tail(array);
  } else {
    unsigned int i;
    data = array->buffer[pos];
    /* Move the following elements left */
    memmove(array->buffer + pos, array->buffer + pos + 1,
            (array->count - pos - 1) * sizeof(void *));
    array->count--;
  }
  return data;
}

void *dynarray_get(const dynarray *array, unsigned int pos) {
  void *data = NULL;
  if (pos < array->count) {
    data = array->buffer[pos];
  }
  return data;
}

void *dynarray_set(dynarray *array, unsigned int pos, void *data) {
  void *temp = NULL;
  if (pos == array->count) {
    dynarray_add_tail(array, data);
  } else if (pos < array->count) {
    temp = array->buffer[pos];
    array->buffer[pos] = data;
  }
  return temp;
}

void dynarray_set_size(dynarray *array, unsigned int size) {
  array->buffer = realloc(array->buffer, size);
  if (array->buffer) {
    array->size = size;
    if (array->size < array->count) {
      array->count = array->size;
    }
  } else {
    array->size = 0;
    array->count = 0;
  }
}

void dynarray_for_each(const dynarray *array, dynarray_forfn fun) {
  unsigned int i;

  for (i = 0; i < array->count; i++) {
    fun(array->buffer[i]);
  }
}

unsigned int dynarray_get_count(const dynarray *array) { return array->count; }

static entry *entry_create(void *item, unsigned int value) {
  entry *e = malloc(sizeof(entry));
  if (e) {
    e->item = item;
    e->value = value;
  }
  return e;
}

minheap *minheap_create(void) {
  minheap *heap = malloc(sizeof(minheap));
  if (heap) {
    heap->entries = dynarray_create();  // TODO: fix this later
  }
  return heap;
}

void minheap_delete(minheap *heap) {
  if (heap) {
    dynarray_for_each(heap->entries, free);
    dynarray_delete(heap->entries);
    free(heap);
  }
}

static void minheap_swap(minheap *heap, unsigned int index1,
                         unsigned int index2) {
  void *temp = dynarray_get(heap->entries, index1);
  dynarray_set(heap->entries, index1, dynarray_get(heap->entries, index2));
  dynarray_set(heap->entries, index2, temp);
}

static void minheap_bubble_up(minheap *heap, unsigned int index) {
  entry *e = dynarray_get(heap->entries, index);
  unsigned int parent_index = (index - 1) / 2;
  entry *parent = dynarray_get(heap->entries, parent_index);
  if (e->value < parent->value) {
    minheap_swap(heap, index, parent_index);
    if (parent_index > 0) {
      minheap_bubble_up(heap, parent_index);
    }
  }
}

static void minheap_bubble_down(minheap *heap, unsigned int index) {
  entry *e = dynarray_get(heap->entries, index);
  unsigned int left_child_index = (index * 2) + 1;
  unsigned int right_child_index = left_child_index + 1;
  unsigned int swapped = 0;
  unsigned int swapped_index;
  if (right_child_index <
          dynarray_get_count(heap->entries) /* There is a right child */
      && ((entry *)dynarray_get(heap->entries, right_child_index))->value <
             ((entry *)dynarray_get(heap->entries, left_child_index))->value
      /* And it's less than left child */
      && e->value >
             ((entry *)dynarray_get(heap->entries, right_child_index))->value) {
    minheap_swap(heap, index, right_child_index);
    swapped = 1;
    swapped_index = right_child_index;
  } else if (e->value >
             ((entry *)dynarray_get(heap->entries, left_child_index))->value) {
    minheap_swap(heap, index, left_child_index);
    swapped = 1;
    swapped_index = left_child_index;
  }
  if (swapped &&
      (swapped_index * 2) + 1 < dynarray_get_count(heap->entries) - 1) {
    minheap_bubble_down(heap, swapped_index);
  }
}

void minheap_add(minheap *heap, void *item, unsigned int value) {
  entry *e = entry_create(item, value);
  if (e) {
    dynarray_add_tail(heap->entries, e);
    unsigned int count = dynarray_get_count(heap->entries);
    if (count > 1) {
      minheap_bubble_up(heap, count - 1);
    }
  }
}

void *minheap_remove_min(minheap *heap) {
  void *item = NULL;
  unsigned int count = dynarray_get_count(heap->entries);
  if (count > 1) {
    minheap_swap(heap, 0, count - 1);
  }
  if (count > 0) {
    entry *e = dynarray_remove_tail(heap->entries);
    item = e->item;
    free(e);
  }
  if (dynarray_get_count(heap->entries) > 1) {
    minheap_bubble_down(heap, 0);
  }
  return item;
}

void minheap_for_each(const minheap *heap, minheap_forfn fun) {
  dynarray_for_each(heap->entries, (dynarray_forfn)fun);
}

unsigned int minheap_get_count(const minheap *heap) {
  return dynarray_get_count(heap->entries);
}