[gcc-src]/libcpp/include/symtab.h:28

```c
/* This is what each hash table entry points to.  It may be embedded
   deeply within another object.  */
typedef struct ht_identifier ht_identifier;
typedef struct ht_identifier *ht_identifier_ptr;
struct GTY(()) ht_identifier {
  const unsigned char *str;
  unsigned int len;
  unsigned int hash_value;
};
```

Ray: Oh, we can use a not full declared type in typedef. Learned.