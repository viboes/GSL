cmake_minimum_required(VERSION 2.8.7)

project(GSL CXX)

set(GSL_HEADERS
    "gsl/gsl"
    "gsl/gsl_assert"
    "gsl/gsl_byte"
    "gsl/gsl_util"
    "gsl/multi_span"
    "gsl/span"
    "gsl/string_span"
    "gsl/gsl_algorithm"
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
 ${BOOST_ROOT} /Users/viboes/github/modular-boost3/
)

install(FILES ${GSL_HEADERS}
    DESTINATION include/gsl
)

enable_testing()

add_subdirectory(tests)
