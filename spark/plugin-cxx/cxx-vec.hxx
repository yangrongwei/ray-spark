/*
 * cxx-vec.hxx
 *
 *  Try to wrap [plug-inc]/vec.h Vector API for GNU compiler.
 *
 *  Created on: Mar 28, 2012
 *      Author: ray
 */

#ifndef CXX_VEC_HXX_
#define CXX_VEC_HXX_

namespace plugin_cxx
{
// -- vec.h:509-540
//#define VEC(T,A) VEC_##T##_##A
//
//Ray:
// This macro generates type name only.
// The actual type (struct) is defined in vec.h:513-540
//
//Ray:  --vec.h:98.101 document
// Macro purpose: variables of vector type declaration
// T == type
// A == allocation strategy   {gc, heap, none}

// -- vec.h:510
//#define VEC_OP(T,A,OP) VEC_##T##_##A##_##OP

// wrap them with C++ class, and try to hide [plug-inc]/vec.h from our client code
// hate macro

//Ray: Wrong method....
//
//// -- vec.h:513
///* Base of vector type, not user visible.  */
////#define VEC_T(T,B)							  \
////typedef struct VEC(T,B) 				 		  \
////{									  \
////  unsigned num;								  \
////  unsigned alloc;							  \
////  T vec[1];								  \
////} VEC(T,B)
//template<typename T>
//class vec_T_B
//{
//public:
//	unsigned num;
//	unsigned alloc;
//	T vec[1];
//};
//
//
//// -- vec.h:537
///* Derived vector type, user visible.  */
////#define VEC_TA(T,B,A)							  \
////typedef struct VEC(T,A)							  \
////{									  \
////  VEC(T,B) base;							  \
////} VEC(T,A)
//template<typename T>
//class vec_T_A : public vec_T_B<T>

enum class _allocation_strategy
{
	gc,
	heap,
	none
};

template<typename T, _allocation_strategy A>
class _vec_agent
{
protected:
	void * vec_ptr;
	_allocation_strategy A;

public:
	typedef T element_type;

public:
//	vec_T_B<T> base;

	/* Length of vector
	   unsigned VEC_T_length(const VEC(T) *v);

	   Return the number of active elements in V.  V can be NULL, in which
	   case zero is returned.  */
	unsigned length();  // -- vec.h:150

	/* Check if vector is empty
	   int VEC_T_empty(const VEC(T) *v);

	   Return nonzero if V is an empty vector (or V is NULL), zero otherwise.  */
	bool empty();  // -- vec.h:158

	/* Get the final element of the vector.
	   T VEC_T_last(VEC(T) *v); // Integer
	   T VEC_T_last(VEC(T) *v); // Pointer
	   T *VEC_T_last(VEC(T) *v); // Object

	   Return the final element.  V must not be empty.  */
	T last();  // -- vec.h:168

	/* Index into vector
	   T VEC_T_index(VEC(T) *v, unsigned ix); // Integer
	   T VEC_T_index(VEC(T) *v, unsigned ix); // Pointer
	   T *VEC_T_index(VEC(T) *v, unsigned ix); // Object

	   Return the IX'th element.  If IX must be in the domain of V.  */
	T index(unsigned ix);  //177

	/* Determine if a vector has additional capacity.

	   int VEC_T_space (VEC(T) *v,int reserve)

	   If V has space for RESERVE additional entries, return nonzero.  You
	   usually only need to use this if you are doing your own vector
	   reallocation, for instance on an embedded vector.  This returns
	   nonzero in exactly the same circumstances that VEC_T_reserve
	   will.  */
	bool space(int reserve); // -- vec.h:249

	/* Reserve space.
	   int VEC_T_A_reserve(VEC(T,A) *&v, int reserve);

	   Ensure that V has at least RESERVE slots available.  This will
	   create additional headroom.  Note this can cause V to be
	   reallocated.  Returns nonzero iff reallocation actually
	   occurred.  */
	bool reserve(int reserve); // -- vec.h:260

	/* Reserve space exactly.
	   int VEC_T_A_reserve_exact(VEC(T,A) *&v, int reserve);

	   Ensure that V has at least RESERVE slots available.  This will not
	   create additional headroom.  Note this can cause V to be
	   reallocated.  Returns nonzero iff reallocation actually
	   occurred.  */
	bool reserve_exact(int reserve); // -- vec.h:271

	/* Push object with no reallocation
	   T *VEC_T_quick_push (VEC(T) *v, T obj); // Integer
	   T *VEC_T_quick_push (VEC(T) *v, T obj); // Pointer
	   T *VEC_T_quick_push (VEC(T) *v, T *obj); // Object

	   Push a new element onto the end, returns a pointer to the slot
	   filled in. For object vectors, the new value can be NULL, in which
	   case NO initialization is performed.  There must
	   be sufficient space in the vector.  */
	T* quick_push(T obj); // -- vec.h:310

public:

	/* Iterate over vector
	   int VEC_T_iterate(VEC(T) *v, unsigned ix, T &ptr); // Integer
	   int VEC_T_iterate(VEC(T) *v, unsigned ix, T &ptr); // Pointer
	   int VEC_T_iterate(VEC(T) *v, unsigned ix, T *&ptr); // Object

	   Return iteration condition and update PTR to point to the IX'th
	   element.  At the end of iteration, sets PTR to NULL.  Use this to
	   iterate over the elements of a vector as follows,

	     for (ix = 0; VEC_iterate(T,v,ix,ptr); ix++)
	       continue;  */
	//#define VEC_iterate(T,V,I,P)	(VEC_OP(T,base,iterate)(VEC_BASE(V),I,&(P)))
	bool iterate (unsigned ix, T& ptr ); // -- vec.h:191

	// -- vec.h:196
	/* Convenience macro for forward iteration.  */
	//#define FOR_EACH_VEC_ELT(T, V, I, P)		\
	//  for (I = 0; VEC_iterate (T, (V), (I), (P)); ++(I))

	//Ray:
	// 1. refine to C++11 the-rang-based for statement
	// n3242-c++11-final-draft-sec-6.5.4-the-rang-based-for-statement
	// stmt.ranged for(:)
	//
	// 2. refine to C++ standard library iterator idiom
	class _iterator
	{

	};


	class _reverse_iterator
	{

	};
public:
	/* Use these to determine the required size and initialization of a
	   vector embedded within another structure (as the final member).

	   size_t VEC_T_embedded_size(int reserve);
	   void VEC_T_embedded_init(VEC(T) *v, int reserve);

	   These allow the caller to perform the memory allocation.  */
	static size_t embedded_size(int reserve);  // -- vec.h:228
	static void embedded_init( void * v , int reserve); // -- vec.h:229
public:
	/* Copy a vector.
	   VEC(T,A) *VEC_T_A_copy(VEC(T) *);

	   Copy the live elements of a vector into a new vector.  The new and
	   old vectors need not be allocated by the same mechanism.  */

//	#define VEC_copy(T,A,V) (VEC_OP(T,A,copy)(VEC_BASE(V) MEM_STAT_INFO))


};

// -- vec.h:543  Ray: Useless in C++
///* Convert to base type.  */
//#define VEC_BASE(P)  ((P) ? &(P)->base : 0)


}// end namespace plugin_cxx


#endif /* CXX_VEC_HXX_ */
