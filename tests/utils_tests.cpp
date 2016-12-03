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
#include <gsl/gsl>
#include <functional>

using namespace gsl;

void f(int& i)
{
    i += 1;
}

struct F {
  int& i;
  F(int& i) : i(i) {}
  void operator()() {f(i);}
};

SUITE(utils_tests)
{

    TEST(finally_functor)
    {
        int i = 0;
        {
            final_act<F> _= finally(F(i));
            CHECK(i == 0);
        }
        CHECK(i == 1);
    }


    TEST(finally_functor_move)
    {
        int i = 0;
        {
            final_act<F> _1 = finally(F(i));
            {
                final_act<F> _2 = boost::move(_1);
                CHECK(i == 0);
            }
            CHECK(i == 1);
            {
                final_act<F> _2 = boost::move(_1);
                CHECK(i == 1);
            }
            CHECK(i == 1);
        }
        CHECK(i == 1);
    }
#if __cplusplus >= 201102L
    TEST(finally_function_with_bind)
    {
        int i = 0;
        {
            auto _ = finally(std::bind(&f, std::ref(i)));
            CHECK(i == 0);
        }
        CHECK(i == 1);
    }
#endif
    int j = 0;
    void g() { j += 1; }
    TEST(finally_function_ptr)
    {
        j = 0;
        {
            final_act<void(*)()> _ = finally(&g);
            CHECK(j == 0);
        }
        CHECK(j == 1);
    }

    TEST(narrow_cast)
    {
        int n = 120;
        char c = narrow_cast<char>(n);
        CHECK(c == 120);

        n = 300;
        unsigned char uc = narrow_cast<unsigned char>(n);
        CHECK(uc == 44);
    }

    TEST(narrow)
    {
        int n = 120;
        char c = narrow<char>(n);
        CHECK(c == 120);

        n = 300;
        CHECK_THROW(narrow<char>(n), narrowing_error);

        const int32_t int32_max = std::numeric_limits<int32_t>::max();
        const int32_t int32_min = std::numeric_limits<int32_t>::min();

        CHECK(narrow<uint32_t>(int32_t(0)) == 0);
        CHECK(narrow<uint32_t>(int32_t(1)) == 1);
        CHECK(narrow<uint32_t>(int32_max) == static_cast<uint32_t>(int32_max));

        CHECK_THROW(narrow<uint32_t>(int32_t(-1)), narrowing_error);
        CHECK_THROW(narrow<uint32_t>(int32_min), narrowing_error);

        n = -42;
        CHECK_THROW(narrow<unsigned>(n), narrowing_error);
    }
}

int main(int, const char *[])
{
    return UnitTest::RunAllTests();
}
