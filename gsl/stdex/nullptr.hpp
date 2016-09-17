///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2016 Vicente J. Botet Escriba. All rights reserved.
//
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

#pragma once

#ifndef STDEX_NULLPTR_H
#define STDEX_NULLPTR_H

#include <cstddef>

#if __cplusplus <= 199711L
namespace stdex {
  template <class T>
  T* make_nullptr()
  { return reinterpret_cast<T*>(0); }

#if defined GSS_NULLPTR_IS_A_STRONG_TYPE
    struct nullptr_t {
        nullptr_t() {}
        template <class T>
        operator T*() const { return 0; }
    };
#else
    typedef void* nullptr_t;
#endif

}
#if defined GSS_NULLPTR_IS_A_STRONG_TYPE
const stdex::nullptr_t NULLPTR;
#endif
#define  NULLPTR 0

#else

namespace stdex {
  using std::nullptr_t;
}
#define NULLPTR nullptr
#endif


#endif // STDEX_ITERATOR_H
