/**
@file memoman.c Defines functions for the memory manager of
 Kalashnikov DB
*/
/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * dbman.c
 * Copyright (C) Markus Schatten 2009 <markus.schatten@foi.hr>
 * 
 * main.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * main.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "memoman.h"

/**
Initializes the global cache memory (variable db_cache)

@return EXIT_SUCCESS if the cache memory has been initialized, EXIT_ERROR otherwise
*/
int KK_cache_malloc()
{
	return EXIT_SUCCESS;
}

/**
Initializes the global redo log memory (variable redo_log)

@return EXIT_SUCCESS if the redo log memory has been initialized, EXIT_ERROR otherwise
*/
int KK_redo_log_malloc()
{
	return EXIT_SUCCESS;
}

/**
Initializes the global query memory (variable query_mem)

@return EXIT_SUCCESS if the query memory has been initialized, EXIT_ERROR otherwise
*/
int KK_query_mem_malloc()
{
	printf("Start query_mem_malloc");
	if( (query_mem = ( KK_query_mem * ) malloc ( sizeof( KK_query_mem) ) ) == NULL )
	{
		printf( " KK_query_mem: ERROR. Cannot allocate memory \n");
		exit( EXIT_ERROR );
	}
	
	KK_query_mem_lib * query_mem_lib;
	if(( query_mem_lib = (KK_query_mem_lib *) malloc(sizeof(KK_query_mem_lib)) ) == NULL )
	{
		printf( " KK_query_mem_lib: ERROR. Cannot allocate memory \n");
		exit( EXIT_ERROR );
	}
	
	KK_query_mem_dict * query_mem_dict;
	if( (query_mem_dict = ( KK_query_mem_dict *) malloc(sizeof(KK_query_mem_dict)) ) == NULL )
	{
		printf( "  KK_query_mem_dict: ERROR. Cannot allocate memory \n");
		exit( EXIT_ERROR );
	}
	
	KK_query_mem_result * query_mem_result;
	if(( query_mem_result = (KK_query_mem_result *) malloc(sizeof(KK_query_mem_result)) ) == NULL )
	{
		printf( "  KK_query_mem_result: ERROR. Cannot allocate memory \n");
		exit( EXIT_ERROR );
	}
	
	
	KK_tuple_dict * tuple_dict = (KK_tuple_dict *) malloc(sizeof(KK_tuple_dict));
	if(( tuple_dict = (KK_tuple_dict *) malloc(sizeof(KK_tuple_dict)) ) == NULL )
	{
		printf( "  KK_tuple_dict: ERROR. Cannot allocate memory \n");
		exit( EXIT_ERROR );
	}
	

	memcpy(query_mem_dict->dictionary,tuple_dict,sizeof(* tuple_dict));

	query_mem->parsed = query_mem_lib;
	query_mem->dictionary = query_mem_dict;
	query_mem->result = query_mem_result;
/*	memcpy(query_mem->parsed, query_mem_lib, sizeof(* query_mem_lib));
	memcpy(query_mem->dictionary,query_mem_dict,sizeof(* query_mem_dict));
	memcpy(query_mem->result,query_mem_result,sizeof(* query_mem_result));*/
	
	printf("END; Success query_mem_malloc");
	return EXIT_SUCCESS;
}

/**
Initializes memory manager (cache, redo log and query memory)

@return EXIT_SUCCESS if the query memory manager has been initialized, EXIT_ERROR otherwise
*/
int KK_memoman_init()
{
	return EXIT_SUCCESS;
}

/**
Caches a block into memory (LIFO)

@param num block number (address)
@return EXIT_SUCCESS if the block has been successfully read into memory, EXIT_ERROR otherwise
*/
int KK_cache_block( int num )
{
	return EXIT_SUCCESS;
}

/**
Reads a block from memory. If the block is cached returns the cached block. Else uses
KK_cache_block to read the block to cache and then returns it.

@param num block number (address)
@return the block given i succesfull, EXIT_ERROR otherwise
*/
KK_mem_block * KK_read_block( int num )
{
	return EXIT_SUCCESS;
}