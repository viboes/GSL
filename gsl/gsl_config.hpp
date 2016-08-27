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

#ifndef GSL_CONFIG_H
#define GSL_CONFIG_H

#include <boost/config.hpp>
#include <boost/type_traits/alignment_of.hpp>



#ifdef _MSC_VER
#define GSL_NO_CXX11_CONSTEXPR
#define GSL_CONSTEXPR
#define GSL_NO_CXX14_CONSTEXPR
#define GSL_CXX14_CONSTEXPR
#define GSL_MUTABLE_CONSTEXPR
#define GSL_DEFAULT_CONSTEXPR
#define GSL_CONTRACT_CONSTEXPR
#if _MSC_VER <= 1800
#define GSL_NO_CXX11_CONSTEXPR
#define GSL_NOEXCEPT
#else
#define GSL_NOEXCEPT noexcept
#endif

#else
#if __cplusplus >= 201102L
#define GSL_ALIGNOF(X) alignof(X)

#define GSL_CONSTEXPR constexpr
#define GSL_NOEXCEPT noexcept

#if __cplusplus >= 201402L
#define GSL_CXX14_CONSTEXPR constexpr
#define GSL_MUTABLE_CONSTEXPR constexpr
#define GSL_DEFAULT_CONSTEXPR constexpr
#define GSL_CONTRACT_CONSTEXPR constexpr
#else
#define GSL_NO_CXX14_CONSTEXPR
#define GSL_CXX14_CONSTEXPR
#define GSL_MUTABLE_CONSTEXPR
#define GSL_DEFAULT_CONSTEXPR
#define GSL_CONTRACT_CONSTEXPR
#endif
#else
#ifndef nullptr
#define nullptr 0
#endif
#define GSL_ALIGNOF(X) boost::alignment_of<X>::value

#define GSL_NO_CXX11_CONSTEXPR
#define GSL_CONSTEXPR
#define GSL_NO_CXX11_CONSTEXPR
#define GSL_NOEXCEPT

#define GSL_NO_CXX14_CONSTEXPR
#define GSL_CXX14_CONSTEXPR
#define GSL_MUTABLE_CONSTEXPR
#define GSL_DEFAULT_CONSTEXPR
#define GSL_CONTRACT_CONSTEXPR

#endif
#endif // _MSC_VER

#endif // GSL_CONFIG_H
