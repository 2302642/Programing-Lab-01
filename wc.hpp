// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.
/*!**************************************************************************************************************************************************************************************************************************
\file       wc.hpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202    
\par        Section:         RSE
\par        Tutorial:        Lab 1
\par        File created on: 12/01/2024
\brief       reading data from file and identify the number of lines, words and bytes in the file

\par        File information:
            This file is contains 1 function definitions to called by main in wc-driver.
            Functions:
            - void wc(int argc, char **argv);                                                                                     // reading data from file and identify the number of lines, words and bytes in the file
*****************************************************************************************************************************************************************************************************************************/

// Our convention is use suffix hpp for header files that will be consumed by C++ source files!!!

// We must always provide header guards in every header file to avoid types being defined
// multiple times [which will be flagged by the compiler]. This happens when this file
// will be included multiple times in a source file.
#ifndef WC_HPP
#define WC_HPP

// No header files must be included here!!!
// The presence of preprocesser directive include in this file will prevent compilation of your code.

// To avoid name clashes, everything we do this must be declared and defined in namespace hlp2:

namespace hlp2 {

// Add function-level Doxygen documentation block for function wc!!!
void wc(int argc, char *argv[]);                                                                            // reading data from file and identify the number of lines, words and bytes in the file
// add declaration of function wc in this namespace

} // end namespace hlp2

#endif // end header guard
