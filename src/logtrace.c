#include <logtrace.h>

#include <time.h>
#include <stdio.h>
#include <string.h>

/**
 * @file logtrace.c
 * @brief Logging utility for error handling in C.
 *
 * This file provides functions to log errors with timestamps and additional context.
 */

/**
 * @brief Logs an error message to a file with a timestamp.
 *
 * This function logs the error number, library name, function name, and a custom message
 * to a log file named `<library>_error.log`. The log entry includes a timestamp.
 *
 * @param error_no The error number to log.
 * @param library The name of the library where the error occurred.
 * @param function The name of the function where the error occurred.
 * @param message A custom message describing the error.
 */
void log_error( const int error_no, const char *library, const char *function, const char *message){
    time_t raw_time;
    time( &raw_time );
    struct tm *timeinfo= localtime( &raw_time );
    char time_str[20];
    strftime( time_str , sizeof( time_str ) , "%F %T" , timeinfo );
    char path[64]= "";
    snprintf( path , sizeof(path) , "%s_error.log", library);
    FILE *error_log= NULL;
    error_log= fopen( path , "a" );
    fprintf( error_log , "(%i) %s | %s | lib[%s] func:[%s] **%s**\n", error_no , strerror( error_no) , time_str , library , function , message);
    fclose( error_log );
}