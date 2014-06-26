```c
//Ray: 'tree type-system' type check. 
// CODE represents a specific type id (enum tree_code) for 'tree'
// T    represents a given 'tree'
//
// -- tree.h:663
#define TREE_CHECK(T, CODE) __extension__				\
({  __typeof (T) const __t = (T);					\
    if (TREE_CODE (__t) != (CODE))					\
      tree_check_failed (__t, __FILE__, __LINE__, __FUNCTION__, 	\
			 (CODE), 0);					\
    __t; })

//Ray: 
// Notice, the pointing data is cast to const, not the pointer itself
// Learned, 'const T'  vs. 'T const' has different effect in macro expansion

// -- system.h:922
#define CONST_CAST_TREE(X) CONST_CAST(union tree_node *, (X))

// -- system.h:921
#define CONST_CAST(TYPE,X) CONST_CAST2(TYPE, const TYPE, (X))

// -- system.h:879==(902, 915, 918)
#define CONST_CAST2(TOTYPE,FROMTYPE,X) (const_cast<TOTYPE> (X))


/////////////////////////////////////

// -- tree.h:870==(939)   // the declaration line
/* In all nodes that are expressions, this is the data type of the expression.
   In POINTER_TYPE nodes, this is the type that the pointer points to.
   In ARRAY_TYPE nodes, this is the type of the elements.
   In VECTOR_TYPE nodes, this is the type of the elements.  */
#define TREE_TYPE(NODE) __extension__ \
(*({__typeof (NODE) const __t = (NODE);					\
    &__t->common.type; }))

//Ray: 
// 1. Whether I is in boundary [0, TREE_OPERAND_LENGTH(T) )
// 2. return exp.operands[I]
// -- tree.h:835
#define TREE_OPERAND_CHECK(T, I)

//Ray: 
// 1. Whether tree code of T is CODE
// 2. and I is in boundary [0, TREE_OPERAND_LENGTH(T) )
// 3. return exp.operands[I]
// -- tree.h:843
#define TREE_OPERAND_CHECK_CODE(T, CODE, I)

// Ray: return exp.operands[I]
// -- tree.h:1581
#define TREE_OPERAND(NODE, I) TREE_OPERAND_CHECK (NODE, I)
```