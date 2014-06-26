```c

//Ray: Number of expression operands
// --[gcc-src]/gcc/tree.c:83
const unsigned char tree_code_length[] = {
//
//Ray: tree_code_length[] cross-reference
VL_EXP_OPERAND_LENGTH()  // -- tree.h:1588
tree_operand_length (const_tree node) // -- tree.h:5607


//Ray: Tree code classes.
// --[gcc-src]/gcc/tree.c:69
const enum tree_code_class tree_code_type[] = {
//
// --[gcc-src]/gcc/tree.c:66
#define DEFTREECODE(SYM, NAME, TYPE, LENGTH) TYPE,
//
//Ray: The 3rd field in tree.def, TYPE , is 'enum tree_code_class'
// That is to say, 
//  The index of tree_code_type[] represents 'enum tree_code'
//  The array element of tree_code_type[] is 'enum tree_code_class' value for its index
// tree_code_type[] is a simple dictionary implemented in array.
//
//Ray: 
// Here is the reason why the index of tree_code_type[] is just 'enum tree_code'.
// Notice, 'enum tree_code' just defins a constant list, not an array, which is tree_code_type[] doing
// --[gcc-inc]/tree.h:42
enum tree_code {
#include "all-tree.def"
MAX_TREE_CODES
};

```