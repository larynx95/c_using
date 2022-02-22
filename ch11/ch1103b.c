/* Data Structures Using C, 2nd, Reema Thareja
Chapter 11. Multi-way Search Trees

# B+ tree
https://github.com/parachvte/B-Plus-Tree/blob/master/main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0
#define MAX_CHILD_NUMBER 3200
#define MAX_KEY 1000000000

typedef struct BPlusTreeNode {
  int isRoot, isLeaf;
  int key_num;
  int key[MAX_CHILD_NUMBER];
  int pos[MAX_CHILD_NUMBER];
  void* child[MAX_CHILD_NUMBER];
  struct BPlusTreeNode* father;
  struct BPlusTreeNode* next;
  struct BPlusTreeNode* last;
} BPlusTreeNode;

struct BPlusTreeNode* Root;

int MaxChildNumber = 50;
int TotalNodes;
int QueryAnsNum;

// file
char input_file[100];
char output_file[100];
char* buffer;
int fsize;
// record
int new_key, new_pos, new_len;
char new_st[12];
// data
const int TotalRecords = 10000000;
int validRecords;
// test
int keys[10000000], key_num;

/**********************************************************
 * Prototypes
 **********************************************************/

extern void BPlusTree_SetMaxChildNumber(int);
extern void BPlusTree_Init();
extern void BPlusTree_Destroy();
extern int BPlusTree_Insert(int, int, void*);
extern int BPlusTree_GetTotalNodes();
extern void BPlusTree_Query_Key(int);
extern void BPlusTree_Query_Range(int, int);
extern void BPlusTree_Modify(int, void*);
extern void BPlusTree_Delete(int);

void build_test();
void query_key_test();
void query_range_test();
void modify_test();
void delete_test();

inline void Read_Buffer(char* input_file);
inline void Read_Data_And_Insert();
int File_Modify(int pos, int key, char* value);
void File_Delete(int pos);
int File_Insert(int new_key, char* new_st);
void ShowHelp();
inline int Binary_Search(BPlusTreeNode* Cur, int key);
void Split(BPlusTreeNode* Cur);
void Insert(BPlusTreeNode* Cur, int key, int pos, void* value);
void Resort(BPlusTreeNode* Left, BPlusTreeNode* Right);
void Redistribute(BPlusTreeNode* Cur);
void Delete(BPlusTreeNode* Cur, int key);
void Destroy(BPlusTreeNode* Cur);
void Print(BPlusTreeNode* Cur);

void Delete(BPlusTreeNode*, int);
void Insert(BPlusTreeNode*, int, int, void*);

/**********************************************************
 * main function
 **********************************************************/

int main(int argc, char* argv[]) {
  // set input_file, output_file
  strcpy(input_file, "data/small-data.txt");
  strcpy(output_file, "data/out.txt");
  if (argc == 2) strcpy(input_file, argv[1]);

  // MainLoop (for presentation)
  MainLoop();

  // build_test();
  // query_key_test();
  // query_range_test();
  // modify_test();
  // delete_test();
  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

void MainLoop() {
  double start_time, end_time;
  int built = false;

  // Read data to buffer
  Read_Buffer(input_file);
  // B+tree initialize
  BPlusTree_Init();
  while (1) {
    ShowHelp();
    int request;
    scanf("%d", &request);
    switch (request) {
      case 0: {
        // Read data to buffer
        if (buffer != NULL) free(buffer);
        Read_Buffer(input_file);
        // B+tree initialize
        BPlusTree_Init();
        // args
        built = false;
        validRecords = 0;
        break;
      }
      case 1: {
        // Set Depth
        printf("input depth: ");
        int depth;
        scanf("%d", &depth);
        int maxCh = 2;
        while (1) {
          int leaves = 1, i;
          for (i = 0; i < depth; i++) {
            leaves *= maxCh;
            if (leaves > TotalRecords) break;
          }
          if (leaves > TotalRecords) break;
          maxCh++;
        }
        printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth,
               maxCh);
        BPlusTree_SetMaxChildNumber(maxCh);
        break;
      }
      case 2: {
        // Set MaxChildNumber
        printf("input MaxChildNumber: ");
        int maxCh;
        scanf("%d", &maxCh);
        BPlusTree_SetMaxChildNumber(maxCh);
        break;
      }
      case 3: {
        // Build B+tree
        if (built == true) {
          printf("You have built the B+tree\n");
          break;
        }
        built = true;
        start_time = clock();
        Read_Data_And_Insert();
        end_time = clock();
        printf("Valid Records inserted on B+tree = %d\n", validRecords);
        printf("Total number of B+tree nodes = %d\n",
               BPlusTree_GetTotalNodes());
        printf("Build B+tree costs %lf s\n",
               (end_time - start_time) / CLOCKS_PER_SEC);
        break;
      }
      case 4: {
        // Query on a key
        printf("input the key: ");
        int key;
        scanf("%d", &key);
        start_time = clock();
        BPlusTree_Query_Key(key);
        end_time = clock();
        printf("Query on a key, costs %lf s\n",
               (end_time - start_time) / CLOCKS_PER_SEC);
        break;
      }
      case 5: {
        // Query on a range [l, r]
        printf("input range [l, r]: ");
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) {
          printf("input illegal\n");
          break;
        }
        start_time = clock();
        BPlusTree_Query_Range(l, r);
        end_time = clock();
        printf("Query on a range, costs %lf s\n",
               (end_time - start_time) / CLOCKS_PER_SEC);
        break;
      }
      case 6: {
        // Modify value on a key
        printf("input (key, value): ");
        scanf("%d %s", &new_key, new_st);
        char* value = (char*)malloc(sizeof(char) * strlen(new_st));
        strcpy(value, new_st);
        start_time = clock();
        int pos = BPlusTree_Find(new_key);
        if (pos != -1) {                            // found
          if (File_Modify(pos, new_key, new_st)) {  // file modify success
            BPlusTree_Modify(new_key, value);
            printf("Modify success.\n");
          } else {
            printf(
                "Modify failed, the new value is too long to store in file\n");
          }
        } else {
          printf("Modify failed, do not have the given key on B+tree.\n");
        }
        end_time = clock();
        printf("Modify value on a key, costs %lf s\n",
               (end_time - start_time) / CLOCKS_PER_SEC);
        break;
      }
      case 7: {
        // Delete value on a key
        printf("input key: ");
        int key;
        scanf("%d", &key);
        start_time = clock();
        int pos = BPlusTree_Find(key);
        if (pos != -1) {  // found
          File_Delete(pos);
          BPlusTree_Delete(key);
          printf("Delete success.\n");
        } else {
          printf("Delete failed, do not have the given key on B+tree.\n");
        }
        end_time = clock();
        printf("Delete value on a key, costs %lf s\n",
               (end_time - start_time) / CLOCKS_PER_SEC);
        break;
      }
      case 8: {
        printf("input (key, value): ");
        scanf("%d %s", &new_key, new_st);
        char* value = (char*)malloc(sizeof(char) * new_len);
        strcpy(value, new_st);

        int pos = BPlusTree_Find(new_key);
        if (pos == -1) {
          new_pos = File_Insert(new_key, new_st);
          keys[key_num++] = new_key;
          BPlusTree_Insert(new_key, new_pos, value);
          validRecords++;
          printf("Insert success.\n");
        } else {
          printf("Insert failed, the key already exist.\n");
        }
        break;
      }
      case 9:
        return;
      default:
        break;
    }
  }
  BPlusTree_Destroy();
}

/**
 * Read_Buffer(char *input_file) -> buffer
 */
inline void Read_Buffer(char* input_file) {
  FILE* fin = fopen(input_file, "rb");
  if (fin == NULL) {
    fputs("File Error\n", stderr);
    exit(1);
  }
  // obtain file size
  fseek(fin, 0, SEEK_END);
  fsize = ftell(fin);
  rewind(fin);
  // allocate memory
  buffer = (char*)malloc(sizeof(char) * fsize);
  if (buffer == NULL) {
    fputs("Memory Error\n", stderr);
    exit(2);
  }
  // read to buffer[]
  fread(buffer, 1, fsize, fin);
  fclose(fin);
}

/** Read and insert records into B+tree */
inline void Read_Data_And_Insert() {
  int rid = 0;
  int cur = 0;
  while (1) {
    while (cur < fsize && !('0' <= buffer[cur] && buffer[cur] <= '9'))
      cur++;  // end of file
    if (cur == fsize) break;

    rid++;
    if (rid % 100000 == 0) printf("now inserting the %d th record ..\n", rid);
    new_key = 0;
    new_pos = cur;
    while (buffer[cur] != ' ' && buffer[cur] != '\t') {
      new_key = new_key * 10 + (buffer[cur] - '0');
      cur++;
    }
    cur++;
    new_len = 0;
    while (buffer[cur] == ' ') cur++;  // util meet a character
    while (cur < fsize && buffer[cur] != '\n') {
      new_st[new_len++] = buffer[cur++];
    }
    new_st[new_len] = '\0';
    char* value = (char*)malloc(sizeof(char) * new_len);
    strcpy(value, new_st);
    keys[key_num++] = new_key;
    if (BPlusTree_Insert(new_key, new_pos, value) == true)
      validRecords++;  // for "ex-data.txt", valid = 9950138
  }
  free(buffer);
  buffer = NULL;
}

/** Modify (key, value) on data file */
int File_Modify(int pos, int key, char* value) {
  int old_key, old_len, len = strlen(value), i;
  char old_value[12];

  FILE* file = fopen(input_file, "r+");
  fseek(file, pos, SEEK_SET);
  fscanf(file, "%d %s", &old_key, old_value);  // read old
  old_len = strlen(old_value);

  if (len > old_len) return false;  // conflict
  // rewrite
  fseek(file, pos - ftell(file), SEEK_CUR);  // return to previous position
  fprintf(file, "%d\t%s", key, value);
  for (i = len; i < old_len; i++) fprintf(file, " ");  // space fill blanks
  fclose(file);
  return true;
}

/** Delete (key, value) on data file */
void File_Delete(int pos) {
  int old_key, i;
  char old_value[12];

  FILE* file = fopen(input_file, "r+");
  fseek(file, pos, SEEK_SET);
  fscanf(file, "%d %s", &old_key, old_value);  // read old
  int end_pos = ftell(file);

  printf("%d %d\n", pos, end_pos);
  // rewrite
  fseek(file, pos - end_pos, SEEK_CUR);  // return to previous position
  for (i = pos; i < end_pos; i++) fprintf(file, " ");  // space fill blanks
  fclose(file);
}

/** Insert (key, value) on data file */
int File_Insert(int new_key, char* new_st) {
  FILE* file = fopen(input_file, "r+");
  fseek(file, 0, SEEK_END);
  int new_pos = ftell(file);

  fprintf(file, "%d %s\n", new_key, new_st);
  fclose(file);
  return new_pos;
}

/** Show Help */
void ShowHelp() {
  printf("\nType your operation:\n");
  printf("  0) Test Initialize\n");
  printf("  1) Set Depth\n");
  printf("  2) Set MaxChildNumber\n");
  printf("  3) Build Tree\n");
  printf("  4) Query on a key\n");
  printf("  5) Query on keys of range [l, r]\n");
  printf("  6) Modify value on a key\n");
  printf("  7) Delete value on a key\n");
  printf("  8) Insert new record\n");
  printf("  9) Quit\n");
}

/** Create a new B+tree Node */
BPlusTreeNode* New_BPlusTreeNode() {
  struct BPlusTreeNode* p =
      (struct BPlusTreeNode*)malloc(sizeof(struct BPlusTreeNode));
  p->isRoot = false;
  p->isLeaf = false;
  p->key_num = 0;
  p->child[0] = NULL;
  p->father = NULL;
  p->next = NULL;
  p->last = NULL;
  TotalNodes++;
  return p;
}

/** Binary search to find the biggest child l that Cur->key[l] <= key */
inline int Binary_Search(BPlusTreeNode* Cur, int key) {
  int l = 0, r = Cur->key_num;
  if (key < Cur->key[l]) return l;
  if (Cur->key[r - 1] <= key) return r - 1;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    if (Cur->key[mid] > key)
      r = mid;
    else
      l = mid;
  }
  return l;
}

void Split(BPlusTreeNode* Cur) {
  // copy Cur(Mid .. MaxChildNumber) -> Temp(0 .. Temp->key_num)
  BPlusTreeNode* Temp = New_BPlusTreeNode();
  BPlusTreeNode* ch;
  int Mid = MaxChildNumber >> 1;
  Temp->isLeaf = Cur->isLeaf;  // Temp's depth == Cur's depth
  Temp->key_num = MaxChildNumber - Mid;
  int i;
  for (i = Mid; i < MaxChildNumber; i++) {
    Temp->child[i - Mid] = Cur->child[i];
    Temp->key[i - Mid] = Cur->key[i];
    if (Temp->isLeaf) {
      Temp->pos[i - Mid] = Cur->pos[i];
    } else {
      ch = (BPlusTreeNode*)Temp->child[i - Mid];
      ch->father = Temp;
    }
  }
  // Change Cur
  Cur->key_num = Mid;
  // Insert Temp
  if (Cur->isRoot) {
    // Create a new Root, the depth of Tree is increased
    Root = New_BPlusTreeNode();
    Root->key_num = 2;
    Root->isRoot = true;
    Root->key[0] = Cur->key[0];
    Root->child[0] = Cur;
    Root->key[1] = Temp->key[0];
    Root->child[1] = Temp;
    Cur->father = Temp->father = Root;
    Cur->isRoot = false;
    if (Cur->isLeaf) {
      Cur->next = Temp;
      Temp->last = Cur;
    }
  } else {
    // Try to insert Temp to Cur->father
    Temp->father = Cur->father;
    Insert(Cur->father, Cur->key[Mid], -1, (void*)Temp);
  }
}

/** Insert (key, value) into Cur, if Cur is full, then split it to fit the
 * definition of B+tree */
void Insert(BPlusTreeNode* Cur, int key, int pos, void* value) {
  int i, ins;
  if (key < Cur->key[0])
    ins = 0;
  else
    ins = Binary_Search(Cur, key) + 1;
  for (i = Cur->key_num; i > ins; i--) {
    Cur->key[i] = Cur->key[i - 1];
    Cur->child[i] = Cur->child[i - 1];
    if (Cur->isLeaf) Cur->pos[i] = Cur->pos[i - 1];
  }
  Cur->key_num++;
  Cur->key[ins] = key;
  Cur->child[ins] = value;
  Cur->pos[ins] = pos;
  if (Cur->isLeaf == false) {  // make links on leaves
    BPlusTreeNode* firstChild = (BPlusTreeNode*)(Cur->child[0]);
    if (firstChild->isLeaf ==
        true) {  // which means value is also a leaf as child[0]
      BPlusTreeNode* temp = (BPlusTreeNode*)(value);
      if (ins > 0) {
        BPlusTreeNode* prevChild;
        BPlusTreeNode* succChild;
        prevChild = (BPlusTreeNode*)Cur->child[ins - 1];
        succChild = prevChild->next;
        prevChild->next = temp;
        temp->next = succChild;
        temp->last = prevChild;
        if (succChild != NULL) succChild->last = temp;
      } else {
        // do not have a prevChild, then refer next directly
        // updated: the very first record on B+tree, and will not come to this
        // case
        temp->next = Cur->child[1];
        printf("this happens\n");
      }
    }
  }
  if (Cur->key_num == MaxChildNumber)  // children is full
    Split(Cur);
}

/** Resort(Give, Get) make their no. of children average */
void Resort(BPlusTreeNode* Left, BPlusTreeNode* Right) {
  int total = Left->key_num + Right->key_num;
  BPlusTreeNode* temp;
  if (Left->key_num < Right->key_num) {
    int leftSize = total >> 1;
    int i = 0, j = 0;
    while (Left->key_num < leftSize) {
      Left->key[Left->key_num] = Right->key[i];
      Left->child[Left->key_num] = Right->child[i];
      if (Left->isLeaf) {
        Left->pos[Left->key_num] = Right->pos[i];
      } else {
        temp = (BPlusTreeNode*)(Right->child[i]);
        temp->father = Left;
      }
      Left->key_num++;
      i++;
    }
    while (i < Right->key_num) {
      Right->key[j] = Right->key[i];
      Right->child[j] = Right->child[i];
      if (Right->isLeaf) Right->pos[j] = Right->pos[i];
      i++;
      j++;
    }
    Right->key_num = j;
  } else {
    int leftSize = total >> 1;
    int i, move = Left->key_num - leftSize, j = 0;
    for (i = Right->key_num - 1; i >= 0; i--) {
      Right->key[i + move] = Right->key[i];
      Right->child[i + move] = Right->child[i];
      if (Right->isLeaf) Right->pos[i + move] = Right->pos[i];
    }
    for (i = leftSize; i < Left->key_num; i++) {
      Right->key[j] = Left->key[i];
      Right->child[j] = Left->child[i];
      if (Right->isLeaf) {
        Right->pos[j] = Left->pos[i];
      } else {
        temp = (BPlusTreeNode*)Left->child[i];
        temp->father = Right;
      }
      j++;
    }
    Left->key_num = leftSize;
    Right->key_num = total - leftSize;
  }
}

/**
 * Redistribute Cur, using following strategy:
 * (1) resort with right brother
 * (2) resort with left brother
 * (3) merge with right brother
 * (4) merge with left brother
 * in that case root has only one child, set this chil to be root
 */

void Redistribute(BPlusTreeNode* Cur) {
  if (Cur->isRoot) {
    if (Cur->key_num == 1 && !Cur->isLeaf) {
      Root = Cur->child[0];
      Root->isRoot = true;
      free(Cur);
    }
    return;
  }
  BPlusTreeNode* Father = Cur->father;
  BPlusTreeNode* prevChild;
  BPlusTreeNode* succChild;
  BPlusTreeNode* temp;
  int my_index = Binary_Search(Father, Cur->key[0]);
  if (my_index + 1 < Father->key_num) {
    succChild = Father->child[my_index + 1];
    if ((succChild->key_num - 1) * 2 >=
        MaxChildNumber) {      // at least can move one child to Cur
      Resort(Cur, succChild);  // (1) resort with right child
      Father->key[my_index + 1] = succChild->key[0];
      return;
    }
  }
  if (my_index - 1 >= 0) {
    prevChild = Father->child[my_index - 1];
    if ((prevChild->key_num - 1) * 2 >= MaxChildNumber) {
      Resort(prevChild, Cur);  // (2) resort with left child
      Father->key[my_index] = Cur->key[0];
      return;
    }
  }
  if (my_index + 1 < Father->key_num) {  // (3) merge with right child
    int i = 0;
    while (i < succChild->key_num) {
      Cur->key[Cur->key_num] = succChild->key[i];
      Cur->child[Cur->key_num] = succChild->child[i];
      if (Cur->isLeaf) {
        Cur->pos[Cur->key_num] = succChild->pos[i];
      } else {
        temp = (BPlusTreeNode*)(succChild->child[i]);
        temp->father = Cur;
      }
      Cur->key_num++;
      i++;
    }
    Delete(Father, succChild->key[0]);  // delete right child
    return;
  }
  if (my_index - 1 >= 0) {  // (4) merge with left child
    int i = 0;
    while (i < Cur->key_num) {
      prevChild->key[prevChild->key_num] = Cur->key[i];
      prevChild->child[prevChild->key_num] = Cur->child[i];
      if (Cur->isLeaf) {
        prevChild->pos[prevChild->key_num] = Cur->pos[i];
      } else {
        temp = (BPlusTreeNode*)(Cur->child[i]);
        temp->father = prevChild;
      }
      prevChild->key_num++;
      i++;
    }
    Delete(Father, Cur->key[0]);  // delete left child
    return;
  }
  printf("What?! you're the only child???\n");  // this won't happen
}

/** Delete key from Cur, if no. of children < MaxChildNUmber / 2, resort or
 * merge it with brothers */
void Delete(BPlusTreeNode* Cur, int key) {
  int i, del = Binary_Search(Cur, key);
  void* delChild = Cur->child[del];
  for (i = del; i < Cur->key_num - 1; i++) {
    Cur->key[i] = Cur->key[i + 1];
    Cur->child[i] = Cur->child[i + 1];
    if (Cur->isLeaf) Cur->pos[i] = Cur->pos[i + 1];
  }
  Cur->key_num--;
  if (Cur->isLeaf == false) {  // make links on leaves
    BPlusTreeNode* firstChild = (BPlusTreeNode*)(Cur->child[0]);
    if (firstChild->isLeaf == true) {  // which means delChild is also a leaf
      BPlusTreeNode* temp = (BPlusTreeNode*)delChild;
      BPlusTreeNode* prevChild = temp->last;
      BPlusTreeNode* succChild = temp->next;
      if (prevChild != NULL) prevChild->next = succChild;
      if (succChild != NULL) succChild->last = prevChild;
    }
  }
  if (del == 0 && !Cur->isRoot) {  // some fathers' key should be changed
    BPlusTreeNode* temp = Cur;
    while (!temp->isRoot && temp == temp->father->child[0]) {
      temp->father->key[0] = Cur->key[0];
      temp = temp->father;
    }
    if (!temp->isRoot) {
      temp = temp->father;
      int i = Binary_Search(temp, key);
      temp->key[i] = Cur->key[0];
    }
  }
  free(delChild);
  if (Cur->key_num * 2 < MaxChildNumber) Redistribute(Cur);
}

/** Find a leaf node that key lays in it
 *	modify indicates whether key should affect the tree
 */
BPlusTreeNode* Find(int key, int modify) {
  BPlusTreeNode* Cur = Root;
  while (1) {
    if (Cur->isLeaf == true) break;
    if (key < Cur->key[0]) {
      if (modify == true) Cur->key[0] = key;
      Cur = Cur->child[0];
    } else {
      int i = Binary_Search(Cur, key);
      Cur = Cur->child[i];
    }
  }
  return Cur;
}

/** Destroy subtree whose root is Cur, By recursion */
void Destroy(BPlusTreeNode* Cur) {
  if (Cur->isLeaf == true) {
    int i;
    for (i = 0; i < Cur->key_num; i++) free(Cur->child[i]);
  } else {
    int i;
    for (i = 0; i < Cur->key_num; i++) Destroy(Cur->child[i]);
  }
  free(Cur);
}

/** Print subtree whose root is Cur */
void Print(BPlusTreeNode* Cur) {
  int i;
  for (i = 0; i < Cur->key_num; i++) printf("%d ", Cur->key[i]);
  printf("\n");
  if (!Cur->isLeaf) {
    for (i = 0; i < Cur->key_num; i++) Print(Cur->child[i]);
  }
}

/** Interface: Insert (key, value) into B+tree */
int BPlusTree_Insert(int key, int pos, void* value) {
  BPlusTreeNode* Leaf = Find(key, true);
  int i = Binary_Search(Leaf, key);
  if (Leaf->key[i] == key) return false;
  Insert(Leaf, key, pos, value);
  return true;
}

/** Interface: query all record whose key satisfy that key = query_key */
void BPlusTree_Query_Key(int key) {
  BPlusTreeNode* Leaf = Find(key, false);
  QueryAnsNum = 0;
  int i;
  for (i = 0; i < Leaf->key_num; i++) {
    // printf("%d ", Leaf->key[i]);
    if (Leaf->key[i] == key) {
      QueryAnsNum++;
      if (QueryAnsNum < 20)
        printf("[no.%d	key = %d, value = %s]\n", QueryAnsNum, Leaf->key[i],
               (char*)Leaf->child[i]);
    }
  }
  printf("Total number of answers is: %d\n", QueryAnsNum);
}

/** Interface: query all record whose key satisfy that query_l <= key <= query_r
 */
void BPlusTree_Query_Range(int l, int r) {
  BPlusTreeNode* Leaf = Find(l, false);
  QueryAnsNum = 0;
  int i;
  for (i = 0; i < Leaf->key_num; i++) {
    // printf("%d ", Leaf->key[i]);
    if (Leaf->key[i] >= l) break;
  }
  int finish = false;
  while (!finish) {
    while (i < Leaf->key_num) {
      if (Leaf->key[i] > r) {
        finish = true;
        break;
      }
      QueryAnsNum++;
      if (QueryAnsNum == 20) printf("...\n");
      if (QueryAnsNum < 20)
        printf("[no.%d	key = %d, value = %s]\n", QueryAnsNum, Leaf->key[i],
               (char*)Leaf->child[i]);
      i++;
    }
    if (finish || Leaf->next == NULL) break;
    Leaf = Leaf->next;
    i = 0;
  }
  printf("Total number of answers is: %d\n", QueryAnsNum);
}

/** Interface: Find the position of given key */
int BPlusTree_Find(int key) {
  BPlusTreeNode* Leaf = Find(key, false);
  int i = Binary_Search(Leaf, key);
  if (Leaf->key[i] != key) return -1;  // don't have this key
  return Leaf->pos[i];
}

/** Interface: modify value on the given key */
void BPlusTree_Modify(int key, void* value) {
  BPlusTreeNode* Leaf = Find(key, false);
  int i = Binary_Search(Leaf, key);
  if (Leaf->key[i] != key) return;  // don't have this key
  printf("Modify: key = %d, original value = %s, new value = %s\n", key,
         (char*)(Leaf->child[i]), (char*)(value));
  free(Leaf->child[i]);
  Leaf->child[i] = value;
}

/** Interface: delete value on the given key */
void BPlusTree_Delete(int key) {
  BPlusTreeNode* Leaf = Find(key, false);
  int i = Binary_Search(Leaf, key);
  if (Leaf->key[i] != key) return;  // don't have this key
  printf("Delete: key = %d, original value = %s\n", key,
         (char*)(Leaf->child[i]));
  Delete(Leaf, key);
}

/** Interface: Called to destroy the B+tree */
void BPlusTree_Destroy() {
  if (Root == NULL) return;
  printf("Now destroying B+tree ..\n");
  Destroy(Root);
  Root = NULL;
  printf("Done.\n");
}

/** Interface: Initialize */
void BPlusTree_Init() {
  BPlusTree_Destroy();
  Root = New_BPlusTreeNode();
  Root->isRoot = true;
  Root->isLeaf = true;
  TotalNodes = 0;
}

/**
 * Interface: setting MaxChildNumber in your program
 * A suggest value is cube root of the no. of records
 */
void BPlusTree_SetMaxChildNumber(int number) { MaxChildNumber = number + 1; }

/** Interface: print the tree (DEBUG use)*/
void BPlusTree_Print() {
  struct BPlusTreeNode* Leaf = Find(1000000000, false);
  int cnt = 0;
  while (Leaf != NULL) {
    int i;
    for (i = Leaf->key_num - 1; i >= 0; i--) {
      printf("%4d ", Leaf->key[i]);
      if (++cnt % 20 == 0) printf("\n");
    }
    Leaf = Leaf->last;
  }
}

/** Interface: Total Nodes */
int BPlusTree_GetTotalNodes() { return TotalNodes; }

//=========================================== TEST
//============================================
// test for database class project
// doing "build", "query_key", "query_range", "modify" and "delete" operations
// 10 times, calc their average time.

void build_test() {
  double start_time, end_time, tot_time = 0;
  int built = false;

  // MaxChildNumber
  printf("input depth: ");
  int depth;
  scanf("%d", &depth);
  int maxCh = 2;
  while (1) {
    int leaves = 1, i;
    for (i = 0; i < depth; i++) {
      leaves *= maxCh;
      if (leaves > TotalRecords) break;
    }
    if (leaves > TotalRecords) break;
    maxCh++;
  }
  printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth, maxCh);
  BPlusTree_SetMaxChildNumber(maxCh);

  // build
  int build_num = 10, i;
  for (i = 0; i < build_num; i++) {
    printf("=============== %d ==========\n", i);
    // read buffer
    Read_Buffer(input_file);
    start_time = clock();
    // B+tree initialize
    BPlusTree_Init();
    // args
    built = false;
    validRecords = 0;
    key_num = 0;
    // build
    built = true;
    Read_Data_And_Insert();
    end_time = clock();
    tot_time += (end_time - start_time);
    printf("Valid Records inserted on B+tree = %d\n", validRecords);
    printf("Total number of B+tree nodes = %d\n", BPlusTree_GetTotalNodes());
    printf("this time costs %lf s\n\n",
           (end_time - start_time) / CLOCKS_PER_SEC);
    BPlusTree_Destroy();
  }
  printf("build %d times, average cost is %lf s\n", build_num,
         tot_time / CLOCKS_PER_SEC / build_num);
}

void query_key_test() {
  double start_time, end_time;
  int built = false;

  Read_Buffer(input_file);
  // B+tree initialize
  BPlusTree_Init();
  // MaxChildNumber
  printf("input depth: ");
  int depth;
  scanf("%d", &depth);
  int maxCh = 2;
  while (1) {
    int leaves = 1, i;
    for (i = 0; i < depth; i++) {
      leaves *= maxCh;
      if (leaves > TotalRecords) break;
    }
    if (leaves > TotalRecords) break;
    maxCh++;
  }
  printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth, maxCh);
  BPlusTree_SetMaxChildNumber(maxCh);
  // build
  built = true;
  start_time = clock();
  Read_Data_And_Insert();
  end_time = clock();
  printf("Valid Records inserted on B+tree = %d\n", validRecords);
  printf("Total number of B+tree nodes = %d\n", BPlusTree_GetTotalNodes());
  printf("Build B+tree costs %lf s\n",
         (end_time - start_time) / CLOCKS_PER_SEC);
  // query
  start_time = clock();
  int key, i;
  srand((unsigned)time(NULL));
  int query_num = 10;
  for (i = 0; i < query_num; i++) {
    key = keys[rand() % key_num];
    BPlusTree_Query_Key(key);
  }
  end_time = clock();
  printf("query %d ranges, average cost is %lf s\n", query_num,
         (end_time - start_time) / CLOCKS_PER_SEC / query_num);
  BPlusTree_Destroy();
}

void query_range_test() {
  double start_time, end_time;
  int built = false;

  Read_Buffer(input_file);
  // B+tree initialize
  BPlusTree_Init();
  // MaxChildNumber
  printf("input depth: ");
  int depth;
  scanf("%d", &depth);
  int maxCh = 2;
  while (1) {
    int leaves = 1, i;
    for (i = 0; i < depth; i++) {
      leaves *= maxCh;
      if (leaves > TotalRecords) break;
    }
    if (leaves > TotalRecords) break;
    maxCh++;
  }
  printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth, maxCh);
  BPlusTree_SetMaxChildNumber(maxCh);
  // build
  built = true;
  start_time = clock();
  Read_Data_And_Insert();
  end_time = clock();
  printf("Valid Records inserted on B+tree = %d\n", validRecords);
  printf("Total number of B+tree nodes = %d\n", BPlusTree_GetTotalNodes());
  printf("Build B+tree costs %lf s\n",
         (end_time - start_time) / CLOCKS_PER_SEC);
  // query
  start_time = clock();
  int key, i;
  srand((unsigned)time(NULL));
  int query_num = 10;
  for (i = 0; i < query_num; i++) {
    int r = ((long long)(rand() % MAX_KEY) * (rand() % MAX_KEY)) % MAX_KEY + 1;
    int l = ((long long)(rand() % MAX_KEY) * (rand() % MAX_KEY)) % r + 1;
    printf("range = (%d, %d)\n", l, r);
    BPlusTree_Query_Range(l, r);
  }
  end_time = clock();
  printf("query %d ranges, average cost is %lf s\n", query_num,
         (end_time - start_time) / CLOCKS_PER_SEC / query_num);
  BPlusTree_Destroy();
}

void modify_test() {
  double start_time, end_time;
  int built = false;

  Read_Buffer(input_file);
  // B+tree initialize
  BPlusTree_Init();
  // MaxChildNumber
  printf("input depth: ");
  int depth;
  scanf("%d", &depth);
  int maxCh = 2;
  while (1) {
    int leaves = 1, i;
    for (i = 0; i < depth; i++) {
      leaves *= maxCh;
      if (leaves > TotalRecords) break;
    }
    if (leaves > TotalRecords) break;
    maxCh++;
  }
  printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth, maxCh);
  BPlusTree_SetMaxChildNumber(maxCh);
  // build
  built = true;
  start_time = clock();
  Read_Data_And_Insert();
  end_time = clock();
  printf("Valid Records inserted on B+tree = %d\n", validRecords);
  printf("Total number of B+tree nodes = %d\n", BPlusTree_GetTotalNodes());
  printf("Build B+tree costs %lf s\n",
         (end_time - start_time) / CLOCKS_PER_SEC);
  // modify
  start_time = clock();
  int key, i, j;
  srand((unsigned)time(NULL));
  int mod_num = 10;
  for (i = 0; i < mod_num; i++) {
    new_key = keys[rand() % key_num];
    new_len = 10;
    for (j = 0; j < new_len; j++) new_st[j] = 'a' + rand() % 26;

    char* value = (char*)malloc(sizeof(char) * strlen(new_st));
    strcpy(value, new_st);
    int pos = BPlusTree_Find(new_key);
    if (pos != -1) {                            // found
      if (File_Modify(pos, new_key, new_st)) {  // file modify success
        BPlusTree_Modify(new_key, value);
        // printf("Modify success.\n");
      } else {
        // printf("Modify failed, the new value is too long to store in
        // file\n");
      }
    } else {
      printf("Modify failed, do not have the given key on B+tree.\n");
    }
  }
  end_time = clock();
  printf("modify %d elements, average cost is %lf s\n", mod_num,
         (end_time - start_time) / CLOCKS_PER_SEC / mod_num);
  BPlusTree_Destroy();
}

void delete_test() {
  double start_time, end_time;
  int built = false;

  Read_Buffer(input_file);
  // B+tree initialize
  BPlusTree_Init();
  // MaxChildNumber
  printf("input depth: ");
  int depth;
  scanf("%d", &depth);
  int maxCh = 2;
  while (1) {
    int leaves = 1, i;
    for (i = 0; i < depth; i++) {
      leaves *= maxCh;
      if (leaves > TotalRecords) break;
    }
    if (leaves > TotalRecords) break;
    maxCh++;
  }
  printf("Desired depth = %d, calculated maxChildNumber = %d\n", depth, maxCh);
  BPlusTree_SetMaxChildNumber(maxCh);
  // build
  built = true;
  start_time = clock();
  Read_Data_And_Insert();
  end_time = clock();
  printf("Valid Records inserted on B+tree = %d\n", validRecords);
  printf("Total number of B+tree nodes = %d\n", BPlusTree_GetTotalNodes());
  printf("Build B+tree costs %lf s\n",
         (end_time - start_time) / CLOCKS_PER_SEC);
  // delete
  start_time = clock();
  int key, i;
  srand((unsigned)time(NULL));
  int del_num = 10;
  for (i = 0; i < del_num; i++) {
    key = keys[rand() % key_num];
    int pos = BPlusTree_Find(key);
    if (pos != -1) {  // found
      File_Delete(pos);
      BPlusTree_Delete(key);
      // printf("Delete success.\n");
    } else {
      // printf("Delete failed, do not have the given key on B+tree.\n");
    }
  }
  end_time = clock();
  printf("delete %d elements, average cost is %lf s\n", del_num,
         (end_time - start_time) / CLOCKS_PER_SEC / del_num);
  BPlusTree_Destroy();
}