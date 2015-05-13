#pragma once

#include <Option.h>

namespace opt {

template <size_t Min, size_t Max>
struct StringLengthConstraint {
public:
	bool operator()(Option& opt) {
		auto size = opt.get().size();
		return Min <= size && size <= Max;
	}
};

} // namespace opt
