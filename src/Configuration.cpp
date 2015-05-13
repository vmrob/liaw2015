#include <initializer_list>

#include "Configuration.h"
#include "Option.h"

namespace opt {

Configuration::Configuration(std::initializer_list<Option> options)
	: _options(options)
{}

void Configuration::print() {
	for (auto&& opt : _options) {
		opt.print();
	}
}

} // namespace opt
