/*
 * cxx-tree-container.hxx
 *
 *  Created on: Mar 20, 2012
 *      Author: ray
 */

#ifndef CXX_TREE_CONTAINER_HXX_
#define CXX_TREE_CONTAINER_HXX_

//Ray: Maybe we can put container abstract class here ??? 2012/3/20-16:12

/*
 * gccint-sec-11.2.3 Containers
Two common container data structures can be represented directly with tree nodes. A
TREE_LIST is a singly linked list containing two trees per node. ...
Given one TREE_LIST node, the next node
is found by following the TREE_CHAIN. If the TREE_CHAINis NULL_TREE, then you have
reached the end of the list.

A TREE_VEC is a simple vector. The TREE_VEC_LENGTH is an integer (not a tree) giving the
number of nodes in the vector. The nodes themselves are accessed using the TREE_VEC_ELT
macro, which takes two arguments. The first is the TREE_VEC in question; the second is an
integer indicating which element in the vector is desired. The elements are indexed from
zero.
*/

/*
 * gccint-sec-11.2.1
All GENERIC trees have two fields in common. First,TREE_CHAINis a pointer that can be
used as a singly-linked list to other trees. The other isTREE_TYPE. Many trees store the
type of an expression or declaration in this field.
*/



#endif /* CXX_TREE_CONTAINER_HXX_ */
