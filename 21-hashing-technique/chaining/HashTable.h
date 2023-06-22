class Node {
  public:
    int data;
    Node *next;
};

class HashTable {
  public:
    Node** HT;
    HashTable();
    int hash(int key);
    void display();
    void insert(int key);
    Node * search(int key);
    int remove(int key);
    ~HashTable();  
};

HashTable::HashTable() {
  this->HT = new Node*[10];
  for (int i = 0; i < 10; ++i) HT[i] = nullptr;
};

int HashTable::hash(int key) {
  return key%10;
};

void HashTable::display() {
  std::cout<<"**********************HASHTABLE**********************"<<std::endl;
  for (int i = 0; i < 10; ++i) {
    if (HT[i]) {
      printf("Index: %d, Address: %p\n", i, HT[i]);
      Node *temp = HT[i];
      while(temp) {
        printf("\tData: %d, Address: %p, Next: %p\n", temp->data, temp, temp->next);
        temp = temp->next;
      };
    } else printf("Index: %d, Address: %p\n", i, HT[i]);
  };
};

HashTable::~HashTable() {
  for (int i = 0;i < 10; ++i) {
    Node *p = HT[i];
    while (HT[i]) {
      HT[i] = HT[i]->next;
      delete p;
      p = HT[i];
    };
  };
  delete [] HT;
};

void HashTable::insert(int key) {
  int hashIndex = hash(key);
  Node *temp = new Node;
  temp->data = key;
  temp->next = nullptr;

  if (HT[hashIndex] == nullptr) {
    HT[hashIndex] = temp;
  } else {
    Node *p = HT[hashIndex];
    Node *q = NULL;

    while (p && p->data < key) {
      q = p;
      p = p->next;
    };
    if (q == NULL) {
      temp->next = HT[hashIndex];
      HT[hashIndex] = temp;
    } else {
      temp->next = q->next;
      q->next = temp;
    };
  };
};

Node * HashTable::search(int key) {
  int hashIndex = hash(key);
  Node *p = HT[hashIndex];
  while(p) {
    if (p->data == key) return p;
    p = p->next;
  };
  return 0;
};

int HashTable::remove(int key) {
  int data;
  int hashIndex = hash(key);
  Node *temp, *p; 
  temp = HT[hashIndex];

  while(temp) {
    if (temp->data == key) {
      if (temp == HT[hashIndex]) {
        data = temp->data;
        HT[hashIndex] = NULL;
      } else {
        p->next = temp->next;
        data = temp->data;
        delete temp;
      };
      return data;
    }
    p = temp;
    temp = temp->next;
  };
  return -1;
}