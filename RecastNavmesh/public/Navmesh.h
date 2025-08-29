// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#ifndef __NAVMESH_H__
#define __NAVMESH_H__


#if !RECAST_UNREAL_ENGINE
#include <new>
#include <wchar.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <float.h>
#include <string.h>
#endif


#define CA_SUPPRESS( WarningNumber )

typedef signed int	 		int32;

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

#endif	// __NAVMESH_H__