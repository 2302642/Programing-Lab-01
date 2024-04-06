// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.
// Your definition of function wc can only rely on the following C++ Standard Library headers:
/*!**************************************************************************************************************************************************************************************************************************
\file       wc.cpp
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

#include <iostream>
#include <iomanip>
#include <fstream>

// The use of functions declared in C Standard Library will be a violation of the Academic Integrity Policy ...
// If you are unsure about whether a function is declared in the Standard C library, use this reference: https://en.cppreference.com/w/c/header

// A text file consists of zero or more linesm, each line terminated by a line feed '\n' character.
// Watch out - don't use Windows OS programs [such as notepad.exe] to open and edit your text files.
// This is because Windows text files terminate each line by a carriage return '\r' character followed by a line feed '\n'.

// We don't want to deal with dynamic memory allocation/deallocation. Instead, we'll assume the longest length
// of a line [in any of the files that we'll process] is 2048 characters [including the null terminating character].

// This is an anonymous namespace - i.e., a namespace with no name.
// Anonymous namespaces are used by C++ programmers to make names declared at global scope private to this source file:
namespace {
  const size_t MAX_LINE_LEN {2048};
}

// In C++ [unlike in C], variable MAX_LINE_LEN is considered a constant expression [i.e. like a literal].
// Therefore, you can define a static char array with dimension MAX_LINE_LEN that can be used to store the
// characters of each line of text that you'll read in each of the source files that you'll process ...

// Helper functions must also be private to this source file and must therefore be declared/defined in
// an anonymous namespace ...
namespace {
  // Declare/define your helper functions here ...
}

// Now, define function wc in namespace hlp2 ...
namespace hlp2 {
  // define function wc here ...
  void wc(int argc, char **argv) {
    int total_lines = 0, total_words = 0, total_bytes = 0;                                                                        // initialize total line, total word, and total byte counters
    bool totaling = false;

    for (int i = 1; i < argc; i++) {                                                                                              // do for the numer of file reqested to check
        int lines = 0, words = 0, bytes = 0;                                                                                      // initialize line, word, and byte for each flie
        std::ifstream file(argv[i]);

        if (!file.is_open()){                                                                                                     // check if file can be opened
          std::cerr << "Unable to open file: " << argv[i] << std::endl;                                                           // print to error stream if file cannot be opend
          continue;
        }

        char bit;
        bool wordcheck = false;
        while (file.get(bit)) {                                                                                                   // get every charcter till the end of file
            if (bit == '\n') { lines++;}                                                                                          // count the number of lines 
            if (bit == ' ' || bit == '\t' || bit == '\n' || bit == '\r'){ wordcheck = false; }                                    // check for word boundaries
            else if (!wordcheck){ wordcheck = true; words++; }                                                                    // count the number of words
            bytes++;                                                                                                              // count the number of bytes
          }
        file.close();

        std::cout <<std::setw(7)<< lines <<std::setw(8)<< words <<std::setw(8)<< bytes << " " << argv[i] << std::endl;            //print statics for each file

        total_lines += lines;   total_words += words;   total_bytes += bytes;                                                     // update total count for all files checked
        if(i>1){totaling = true;}
      }
    if (totaling == true){                                                                                                        // print total statics for all files checked
      std::cout <<std::setw(7)<<  total_lines <<std::setw(8)<< total_words <<std::setw(8)<< total_bytes << " total" << std::endl; 
      }
  }
} // end namespace hlp2
