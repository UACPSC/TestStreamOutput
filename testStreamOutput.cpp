/*
    testStreamOutput.cpp

    Tests the output of an error message from a function.

    While the example is for std::cerr (standard error), the approach
    works for any std::ostream, including std::cout (standard output).
*/

#include <iostream>
#include <sstream>
#include <cassert>

// ensure assert() is not turned off
#ifdef NDEBUG
static_assert(false, "NDEBUG cannot be defined");
#endif

// writes to standard error
void process() {
    std::cerr << "Error message" << '\n';
}

int main() {

    // save the original stream buffer of std::cerr
    std::streambuf* originalCerrBuffer = std::cerr.rdbuf();

    // redirect std::cerr to a stringstream
    std::ostringstream errorCapture;
    std::cerr.rdbuf(errorCapture.rdbuf());

    // call the function that writes to standard error
    process();

    // restore the original buffer of std::cerr
    std::cerr.rdbuf(originalCerrBuffer);

    // test the error message
    assert(errorCapture.str() == "Error message\n");

    return 0;
}
