// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

// #ifndef __NAVMESH_H__
// #define __NAVMESH_H__


#if !RECAST_UNREAL_ENGINE
#include <new>
#include <cmath>
#include <cstdlib>
#include <algorithm>

#include <wchar.h>
#include <stddef.h>
#include <stdio.h>
#include <stdarg.h>
#include <float.h>
#include <string.h>

#define CA_SUPPRESS( WarningNumber )

#define CA_ASSUME( Expr )

#define TEXT( TextStr ) nullptr

#define UE_DEPRECATED(Version, Message) [[deprecated(Message " Please update your code to the new API before upgrading to the next release, otherwise your project will no longer compile.")]]

#define QUICK_SCOPE_CYCLE_COUNTER(Stat)

#define DECLARE_LOG_CATEGORY_EXTERN(CategoryName, DefaultVerbosity, CompileTimeVerbosity)
#define DEFINE_LOG_CATEGORY_STATIC(CategoryName, DefaultVerbosity, CompileTimeVerbosity)
#define DEFINE_LOG_CATEGORY(CategoryName)

#define TRACE_CPUPROFILER_EVENT_SCOPE(Name) 

#define UE_LOG(CategoryName, Verbosity, Format, ...)
#define UE_CLOG(Condition, CategoryName, Verbosity, Format, ...)

#define KINDA_SMALL_NUMBER	(1.e-4f)

#define check(expr)

typedef signed int	 		int32;
typedef unsigned int		uint32;
typedef unsigned char 		uint8;


#ifdef NAVMESH_DLL
	#ifdef _WIN32
		#define NAVMESH_API __declspec(dllexport)
	#else
		#if __GNUC__ >= 4
			#define NAVMESH_API __attribute__ ((visibility ("default")))
		#else
			#define NAVMESH_API
		#endif
	#endif
#else
	#ifdef _WIN32
		#define NAVMESH_API __declspec(dllimport)
	#else
		#if __GNUC__ >= 4
			#define NAVMESH_API __attribute__ ((visibility ("default")))
		#else
			#define NAVMESH_API
		#endif
	#endif
#endif
#endif

// #endif	// __NAVMESH_H__