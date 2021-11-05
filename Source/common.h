#pragma once

#include"atp.h"



#ifndef TRUE
#define TRUE 1
#else
#undef TRUE 
#define TRUE 1
#endif 

#ifndef FALSE
#define FALSE 0
#else
#undef FALSE 
#define FALSE 0
#endif 

//-----------------------------------------------

typedef signed char        int8;
typedef short              int16;
typedef int                int32;
typedef long long          int64;
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;

typedef bool b8;
typedef int b32;

typedef float f32;
typedef double f64;

#define Kilobytes(n)  (n << 10)
#define Megabytes(n)  (n << 20)
#define Gigabytes(n)  (((uint64)n) << 30)
#define Terabytes(n)  (((uint64)n) << 40)

#define MAX_FLOAT          3.402823466e+38F        // max value
#define MIN_FLOAT          1.175494351e-38F        // min normalized positive value
#define UINT64MAX		   0xFFFFFFFFFFFFFFFF	//18446744073709551615
#define INT64MAX		   0x7FFFFFFFFFFFFFFF	//9223372036854775807
#define UINT32MAX		   0xffffffff			
#define INV_UINT32_MAX	   2.328306437e-10F

#define ArrayCount(array) (sizeof(array) / sizeof(array[0]))

#define ERRORBOX(error) {MessageBoxA(0, error, "INVALID CODE PATH!", MB_ICONSTOP | MB_OK); __debugbreak();}


typedef void (*activetest_func)();

//NOTE: Use to set the active test that will run. Will give error if another is set as Active.
#define SET_ACTIVE(name) extern const activetest_func active_test = name