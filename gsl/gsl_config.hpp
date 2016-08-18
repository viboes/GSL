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

#include <type_traits>
#include <iterator>
#include <algorithm>

#ifdef _MSC_VER
#if _MSC_VER <= 1800
#define GSL_CXX14_CONSTEXPR
#else
#define GSL_CXX14_CONSTEXPR constexpr
#endif

#else
#if __cplusplus > 201402L
#define GSL_CXX14_CONSTEXPR constexpr
#else
#define GSL_CXX14_CONSTEXPR
#endif
#endif // _MSC_VER

#endif // GSL_CONFIG_H
