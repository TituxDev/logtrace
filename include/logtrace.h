#ifndef LOGTRACE_H
#define LOGTRACE_H

/**
 * @brief Logs an error message with details about the error.
 * 
 * This function logs the error number, library name, function name, and a custom message
 * to a log file named `<library>_error.log`. The log entry includes a timestamp.
 * @param error_no The error number to log.
 * @param library The name of the library where the error occurred.
 * @param function The name of the function where the error occurred.
 * @param message A custom message describing the error.
 */
void log_error( const int error_no, const char *library, const char *function, const char *message);

#endif