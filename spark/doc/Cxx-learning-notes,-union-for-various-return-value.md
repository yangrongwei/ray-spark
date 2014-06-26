TODO: How to highlight with linenumber in this wiki ???

[plug-inc]/tree.h:1906
```c
/* Immediate use linking structure.  This structure is used for maintaining
   a doubly linked list of uses of an SSA_NAME.  */
typedef struct GTY(()) ssa_use_operand_d {
  struct ssa_use_operand_d* GTY((skip(""))) prev;
  struct ssa_use_operand_d* GTY((skip(""))) next;
  /* Immediate uses for a given SSA name are maintained as a cyclic
     list.  To recognize the root of this list, the location field
     needs to point to the original SSA name.  Since statements and
     SSA names are of different data types, we need this union.  See
     the explanation in struct immediate_use_iterator_d.  */
  union { gimple stmt; tree ssa_name; } GTY((skip(""))) loc;
  tree *GTY((skip(""))) use;
} ssa_use_operand_t;
```

Ray: Learned

Notice union declaration in line 1916 (sorry, I do not find a way to syntax highlight with line number in this wiki). In this style, author wants to emphasize there are various return value for *loc*, to access various return value, using different field declared in union.