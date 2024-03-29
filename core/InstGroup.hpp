// <InstGroup.hpp> -*- C++ -*-

#pragma once

#include <vector>
#include "CoreTypes.hpp"
#include "sparta/utils/SpartaSharedPointer.hpp"
#include "sparta/utils/SpartaSharedPointerAllocator.hpp"

namespace olympia
{
    //! \brief An instruction group is the data type passed between units
    //!
    //! It's faster/easier to copy pointers to an instruction group
    //! than to pass copies of the vectors contained
    class InstGroup
    {
        using InstVector = std::vector<InstQueue::value_type>;
    public:
        using iterator       = InstVector::iterator;
        using const_iterator = InstVector::const_iterator;

        void emplace_back(const typename InstQueue::value_type & inst) {
            insts_.emplace_back(inst);
        }

        iterator begin() { return insts_.begin(); }
        iterator end()   { return insts_.end(); }

        const_iterator begin() const { return insts_.begin(); }
        const_iterator end()   const { return insts_.end(); }

        std::size_t size() const  { return insts_.size(); }
        bool        empty() const { return insts_.empty(); }

    private:
        InstVector insts_;
    };
    extern sparta::SpartaSharedPointerAllocator<InstGroup> instgroup_allocator;
    using InstGroupPtr = sparta::SpartaSharedPointer<InstGroup>;
}
