/*

Copyright (c) 2013, Project OSRM, Dennis Luxen, others
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list
of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef CONTAINERUTILS_H_
#define CONTAINERUTILS_H_

#include <algorithm>
#include <vector>

template <typename T> inline void sort_unique_resize(std::vector<T> &vector)
{
    std::sort(vector.begin(), vector.end());
    const auto number_of_unique_elements = std::unique(vector.begin(), vector.end()) - vector.begin();
    vector.resize(number_of_unique_elements);
}

template <typename T> inline void sort_unique_resize_shrink_vector(std::vector<T> &vector)
{
    sort_unique_resize(vector);
    std::vector<T>().swap(vector);
}

template <typename T> inline void remove_consecutive_duplicates_from_vector(std::vector<T> &vector)
{
    const auto number_of_unique_elements = std::unique(vector.begin(), vector.end()) - vector.begin();
    vector.resize(number_of_unique_elements);
}

template <typename FwdIter, typename Func>
Func for_each_pair(FwdIter iter_begin, FwdIter iter_end, Func func)
{
    if (iter_begin == iter_end)
    {
        return func;
    }

    FwdIter iter_next = iter_begin;
    ++iter_next;

    for (; iter_next != iter_end; ++iter_begin, ++iter_next)
    {
        func(*iter_begin, *iter_next);
    }
    return func;
}

#endif /* CONTAINERUTILS_H_ */
