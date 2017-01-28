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

#define GSL_NULLPTR_IS_A_STRONG_TYPE

#include <cstddef>
#if __cplusplus <= 199711L
#include <boost/smart_ptr/shared_ptr.hpp>
#endif


#if __cplusplus <= 199711L
namespace stdex {
  template <class T>
  T* make_nullptr()
  { return reinterpret_cast<T*>(0); }
}
#if defined GSL_NULLPTR_IS_A_STRONG_TYPE
namespace stdex {
    struct nullptr_t {
        nullptr_t() {}
        template <class T>
        operator boost::shared_ptr<T>() const { return boost::shared_ptr<T>((T*)0); }
        template <class T>
        operator T*() const { return 0; }
    };

    template <class T>
    bool operator==(boost::shared_ptr<T> const& ptr, nullptr_t)  { return ! ptr; }
    template <class T>
    bool operator==(nullptr_t, boost::shared_ptr<T> const& ptr)  { return ! ptr; }
    template <class T>
    bool operator!=(boost::shared_ptr<T> const& ptr, nullptr_t)  { return ptr; }
    template <class T>
    bool operator!=(nullptr_t, boost::shared_ptr<T> const& ptr)  { return ptr; }

}
const stdex::nullptr_t NULLPTR;

#else
namespace stdex {
    typedef void* nullptr_t;
}
#define  NULLPTR 0
#endif



#else

namespace stdex {
  using std::nullptr_t;
}
#define NULLPTR nullptr
#endif


#endif // STDEX_NULLPTR_H
