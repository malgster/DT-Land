# Super Array

## Introduction

An **Array** is a data structure consisting of collection of differents values, *all of the same type* that are contiguous in memory. Each Value is identified by a least one *index* that starts at *0*. In <code>C</code>, an array is itself *Pointer to it's first index*.

The following array is called a **One-dimensional Array** or a **Vector**

![1dArray](https://i.imgur.com/MUNtXpk.jpg)

Arrays can have more than one dimension, for exemple, two-dimensional arrays or **matrices**.

![2dArray](https://i.imgur.com/3JKmmdi.jpg)

But there's isn't really any limits in arrays dimensions.

## In memory 

### Static arrays : 

The previous image showed us how we would as humans represent a two-dimensional array. But in memory, it isn't quite the same. It is more like an array of arrays, laid out contiguously in memory. In <code>C</code>, this mapping is achieved by using a **row-column** ordering sequence :

![2DAMemory](https://i.imgur.com/ONn5W7A.jpg)

The array's first row is placed in memory followed by second row, then the third row etc. this ordering continues until the last row is placed in memory. 

The same logic can be applied to array with more dimensions : a three-dimensional array is an array of two-dimensional arrays. the first one will be mapped like explained before, then the second one, etc.

![3DAMemory](https://i.imgur.com/BVT9gst.jpg)

### Arrays of pointers : 

An array of pointers i a one-dimensional array containing numeros pointers and these pointer can store address values of other variables having the same data type. 

For exemple : allocating a two-dimension array in memory using the <code>malloc</code> function will result in creating an array of pointers to other arrays, that are not necesseraly (and mainly) not represented contiguously. 

Representing arrays in that way is very useful as it allows a more dynamic memory allocation. 

![APointers](https://i.imgur.com/WiQdlkX.jpg)

## Super Arrays : 

Arrays are the only data stucture natively available in <code>C</code> due it's nature. So the implementation that i give here offers secure functions to create arrays of characters dynamically, that can be handled like Strings. Along with the rewriting of several string functions in the <code>"string.h"</code>. 




