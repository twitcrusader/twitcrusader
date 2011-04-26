/*
 * gethttp.h
 *
 *  Created on: Apr 26, 2011
 *      Author: darkstar
 */

#ifndef GETHTTP_H_
#define GETHTTP_H_

#include <stdio.h>
#include <curl/curl.h>

size_t writeFunction( void *ptr, size_t size, size_t nmemb, void *stream);
int get_http(char *url, char *file);

#endif /* GETHTTP_H_ */
