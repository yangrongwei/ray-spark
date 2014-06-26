```c
//[plug-inc]/vec.h:27
/* The macros here implement a set of templated vector types and
   associated interfaces.  These templates are implemented with
   macros, as we're not in C++ land.  The interface functions are
   typesafe and use static inline functions, sometimes backed by
   out-of-line generic functions.  The vectors are designed to
   interoperate with the GTY machinery.
*/
```

```
   Because of the different behavior of structure objects, scalar
   objects and of pointers, there are three flavors, one for each of
   these variants.  Both the structure object and pointer variants
   pass pointers to objects around -- in the former case the pointers
   are stored into the vector and in the latter case the pointers are
   dereferenced and the objects copied into the vector.  The scalar
   object variant is suitable for int-like objects, and the vector
   elements are returned by value.
```

由于 结构体（structure objects）, 标量值（scalar objects）与指针（pointers）有着不同的举止行为，（所以）有三大不风味的 vector 来分别应对这三种情况。
存放结构体、指针的 vector 来回传递的都是 object 的指针：在存放结构体的 vector 中，存放的就是指针；在存放指针的 vector 中，会先将指针提领（dereference），在将object复制到 vector 中。  ￥什么意思啊？就是说传递的是指针的指针？干嘛这么费劲？看到代码再说吧……

```
   There are both 'index' and 'iterate' accessors.  The iterator
   returns a boolean iteration condition and updates the iteration
   variable passed by reference.  Because the iterator will be
   inlined, the address-of can be optimized away.
```
vector 有两种访问方式：基于下标的（index）和基于 迭代器（iterate）的。

```
   The vectors are implemented using the trailing array idiom, thus
   they are not resizeable without changing the address of the vector
   object itself.  This means you cannot have variables or fields of
   vector type -- always use a pointer to a vector.  The one exception
   is the final field of a structure, which could be a vector type.
   You will have to use the embedded_size & embedded_init calls to
   create such objects, and they will probably not be resizeable (so
   don't use the 'safe' allocation variants).  The trailing array
   idiom is used (rather than a pointer to an array of data), because,
   if we allow NULL to also represent an empty vector, empty vectors
   occupy minimal space in the structure containing them.
```
￥：trailing array idiom 是什么？
…… 这就是说，你不会（cannot）拥有是 vector 类型的变量或字段（field），永远是指向 vector 类型的指针类型。
唯一的例外是结构体的最后一字段，只有它可以是 vector 类型。




