GSL: Guideline Support Library 
=================================

# viboes/GSL fork - c++11/C++14+C++1z branch

This is the C++11 fork of the GSL LIbrary, to make it compile for C++11 compilers.

Note that the CMakeList.txt needs to be adapted yet so that you will need to hack them  :(

The fork adds a gsl_config.hpp file to manage with C++14 constexpr and the definition in stdex of some C++14 library missing in C++11.

The GSL sources have been modified taking in account the constexpr macro and the stdex features.

THe C++11/C++14/C++1z tests have been run on:

* OS X El Capitan using
 
  * CLANG-3.7.0, CLANG-3.9.0
  * GCC-5.2.0, GCC-6.1.0  

Some useful links

* Brief documentation of [GSL: Guideline support library](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-gsl).

* [Talks and slides](https://github.com/isocpp/CppCoreGuidelines/tree/master/talks) related to GSL and the C++ Core Guielines in particular:

  * “Evolving array_view and string_view for safe C++ code"
   
    * [Talk](https://www.youtube.com/watch?v=C4Z3c4Sv52U)
    * [Slides](https://github.com/isocpp/CppCoreGuidelines/blob/master/talks/MacIntosh%20-%20A%20Few%20Good%20Types.pdf) 

  Even if these presentation doesn't use completly the span interface it is worth wtching it.  

  * "Writing Good C++14... By Default"
  
    * [Talk](https://www.youtube.com/watch?v=hEx5DNLWGgA&list=PLHTh1InhhwT75gykhs7pqcR_uSiG601oh&index=2)
    * [Slides](https://github.com/isocpp/CppCoreGuidelines/blob/master/talks/Sutter%20-%20CppCon%202015%20day%202%20plenary%20.pdf)

# Microsoft/GSL

The Guideline Support Library (GSL) contains functions and types that are suggested for use by the
[C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines) maintained by the [Standard C++ Foundation](https://isocpp.org).
This repo contains Microsoft's implementation of GSL.

The library includes types like `span<T>`, `string_span`, `owner<>` and others.

The entire implementation is provided inline in the headers under the [gsl](./gsl) directory. The implementation generally assumes a platform that implements C++14 support. There are specific workarounds to support MSVC 2013 and 2015.

While some types have been broken out into their own headers (e.g. [gsl/span](./gsl/span)),
it is simplest to just include [gsl/gsl](./gsl/gsl) and gain access to the entire library.

> NOTE: We encourage contributions that improve or refine any of the types in this library as well as ports to
other platforms. Please see [CONTRIBUTING.md](./CONTRIBUTING.md) for more information about contributing.

# Project Code of Conduct
This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

# Quick Start
## Supported Platforms
The test suite that exercises GSL has been built and passes successfully on the following platforms:

* Windows using Visual Studio 2013
* Windows using Visual Studio 2015
* Windows using Clang/LLVM 3.6
* Windows using GCC 5.1
* GNU/Linux using Clang/LLVM 3.6
* GNU/Linux using GCC 5.1
* OS X Yosemite using Xcode with AppleClang 7.0.0.7000072
* OS X Yosemite using GCC-5.2.0
* FreeBSD 10.x with Clang/LLVM 3.6

> If you successfully port GSL to another platform, we would love to hear from you. Please submit an issue to let us know. Also please consider
contributing any changes that were necessary back to this project to benefit the wider community.

## Building the tests
To build the tests, you will require the following:

* [CMake](http://cmake.org), version 2.8.7 or later to be installed and in your PATH.
* [UnitTest-cpp](https://github.com/Microsoft/unittest-cpp), to be cloned under the [tests/unittest-cpp](./tests/unittest-cpp) directory
of your GSL source.

These steps assume the source code of this repository has been cloned into a directory named `c:\GSL`.

1. Create a directory to contain the build outputs for a particular architecture (we name it c:\GSL\build-x86 in this example).

        cd GSL
        md build-x86
        cd build-x86

2. Configure CMake to use the compiler of your choice (you can see a list by running `cmake --help`).

        cmake -G "Visual Studio 14 2015" c:\GSL

3. Build the test suite (in this case, in the Debug configuration, Release is another good choice).    

        cmake --build . --config Debug

4. Run the test suite.    

        ctest -C Debug

All tests should pass - indicating your platform is fully supported and you are ready to use the GSL types!

## Using the libraries
As the types are entirely implemented inline in headers, there are no linking requirements.

You can copy the [gsl](./gsl) directory into your source tree so it is available
to your compiler, then include the appropriate headers in your program.

Alternatively set your compiler's *include path* flag to point to the GSL development folder (`c:\GSL` in the example above) or installation folder (after running the install). Eg.

MSVC++

    /I c:\GSL

GCC/clang

    -I$HOME/dev/GSL

Include the library using:

    #include <gsl/gsl>


    
