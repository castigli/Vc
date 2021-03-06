/*  This file is part of the Vc library. {{{
Copyright © 2014-2015 Matthias Kretz <kretz@kde.org>

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the names of contributing organizations nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

}}}*/

#ifndef VC_COMMON_SIMD_CAST_CALLER_TCC_
#define VC_COMMON_SIMD_CAST_CALLER_TCC_

#include "macros.h"
namespace Vc_VERSIONED_NAMESPACE {
template <class T, std::size_t N, class VectorType>
template <class U, class V, class>
Vc_INTRINSIC SimdMaskArray<T, N, VectorType, N>::SimdMaskArray(
    const SimdMaskArray<U, N, V> &x)
    : data(simd_cast<mask_type>(internal_data(x)))
{
}
template <class T, std::size_t N, class VectorType>
template <class U, class V, class, class>
Vc_INTRINSIC SimdMaskArray<T, N, VectorType, N>::SimdMaskArray(
    const SimdMaskArray<U, N, V> &x)
    : data(simd_cast<mask_type>(internal_data(internal_data0(x)),
                                internal_data(internal_data1(x))))
{
}
template <class T, std::size_t N, class VectorType>
template <class U, class V, class, class, class>
Vc_INTRINSIC SimdMaskArray<T, N, VectorType, N>::SimdMaskArray(
    const SimdMaskArray<U, N, V> &x)
    : data(simd_cast<mask_type>(internal_data(internal_data0(internal_data0(x))),
                                internal_data(internal_data1(internal_data0(x))),
                                internal_data(internal_data0(internal_data1(x))),
                                internal_data(internal_data1(internal_data1(x)))))
{
}
// conversion from any Segment object (could be SimdMaskArray or Mask<T>)
template <class T, std::size_t N, class VectorType>
template <class M, std::size_t Pieces, std::size_t Index>
Vc_INTRINSIC SimdMaskArray<T, N, VectorType, N>::SimdMaskArray(
    Common::Segment<M, Pieces, Index> &&x,
    enable_if<Traits::simd_vector_size<M>::value == Size * Pieces>)
    : data(simd_cast<mask_type, Index>(x.data))
{
}
// conversion from Mask<T>
template <class T, std::size_t N, class VectorType>
template <class M, class>
Vc_INTRINSIC SimdMaskArray<T, N, VectorType, N>::SimdMaskArray(M k)
    : data(simd_cast<mask_type>(k))
{
}

}  // namespace Vc_VERSIONED_NAMESPACE

#endif  // VC_COMMON_SIMD_CAST_CALLER_TCC_

// vim: foldmethod=marker
