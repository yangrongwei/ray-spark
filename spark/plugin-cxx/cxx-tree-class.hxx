/*
 * cxx-tree-class.h
 *
 *  Created on: Mar 18, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_CLASS_H_
#define CXX_TREE_CLASS_H_

namespace plugin_cxx
{



// -- [plugin-inc]/tree.h:347
/* A tree node can represent a data type, a variable, an expression
   or a statement.  Each node has a TREE_CODE which says what kind of
   thing it represents. ...

   As for the contents of a tree node: there are some fields
   that all nodes share.  Each TREE_CODE has various special-purpose
   fields as well.  The fields of a node are never accessed directly,
   always through accessor macros.  */


// -- [plugin-inc]/tree.h:61
//Ray: We have various tree_code, but only limited tree_code_class.
//     The purpose of tree_code_class should be *classifying* tree_code.
//
/* Each tree_code has an associated code class represented by a
   TREE_CODE_CLASS.  */


#endif /* CXX_TREE_CLASS_H_ */
