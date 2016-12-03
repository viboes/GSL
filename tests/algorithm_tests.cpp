///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
///////////////////////////////////////////////////////////////////////////////

#include <UnitTest++/UnitTest++.h>
#include <gsl/gsl_algorithm>

#include <boost/array.hpp>

using namespace std;
using namespace gsl;

SUITE(copy_tests)
{

    TEST(same_type)
    {
        // dynamic source and destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<int, 10> dst = {};

            span<int> src_span(src);
            span<int> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // static source and dynamic destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<int, 10> dst = {};

            span<int, 5> src_span(src);
            span<int> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // dynamic source and static destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<int, 10> dst = {};

            span<int> src_span(src);
            span<int, 10> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // static source and destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<int, 10> dst = {};

            span<int, 5> src_span(src);
            span<int, 10> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }
    }

    TEST(compatible_type)
    {
        // dynamic source and destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<char, 10> dst = {};

            span<int> src_span(src);
            span<char> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // static source and dynamic destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<char, 10> dst = {};

            span<int, 5> src_span(src);
            span<char> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // dynamic source and static destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<char, 10> dst = {};

            span<int> src_span(src);
            span<char, 10> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }

        // static source and destination span
        {
            boost::array<int, 5> src = {1, 2, 3, 4, 5};
            boost::array<char, 10> dst = {};

            span<int, 5> src_span(src);
            span<char, 10> dst_span(dst);

            copy(src_span, dst_span);
            copy(src_span, dst_span.subspan(src_span.size()));

            for (std::size_t i = 0; i < src.size(); ++i) {
                CHECK(dst[i] == src[i]);
                CHECK(dst[i + src.size()] == src[i]);
            }
        }
    }

#ifdef CONFIRM_COMPILATION_ERRORS
    TEST(incompatible_type)
    {
        boost::array<int, 4> src = {1, 2, 3, 4};
        boost::array<int*, 12> dst = {};

        span<int> src_span_dyn(src);
        span<int, 4> src_span_static(src);
        span<int*> dst_span_dyn(dst);
        span<int*, 4> dst_span_static(dst);

        // every line should produce a compilation error
        copy(src_span_dyn,    dst_span_dyn);
        copy(src_span_dyn,    dst_span_static);
        copy(src_span_static, dst_span_dyn);
        copy(src_span_static, dst_span_static);
    }
#endif

    TEST(small_destination_span)
    {
        boost::array<int, 12> src = {1, 2, 3, 4};
        boost::array<int, 4> dst = {};

        span<int> src_span_dyn(src);
        span<int, 12> src_span_static(src);
        span<int> dst_span_dyn(dst);
        span<int, 4> dst_span_static(dst);

        CHECK_THROW(copy(src_span_dyn,    dst_span_dyn),    fail_fast);
        CHECK_THROW(copy(src_span_dyn,    dst_span_static), fail_fast);
        CHECK_THROW(copy(src_span_static, dst_span_dyn),    fail_fast);

#ifdef CONFIRM_COMPILATION_ERRORS
        copy(src_span_static, dst_span_static);
#endif
    }
}

int main(int, const char* []) { return UnitTest::RunAllTests(); }

