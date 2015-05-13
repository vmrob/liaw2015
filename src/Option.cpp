#include "Option.h"

namespace opt {

Option::Option(Option* parent)
	: _parent(parent)
{}

size_t Option::getDepth() {
	size_t depth = 0;
	auto _nextParent = _parent;
	while(_nextParent) {
		++depth;
		_nextParent = _nextParent->_parent;
	}
	return depth;
}

void Option::print() {
	std::string indent(getDepth() * 4, ' ');
	std::cout << indent << "name: " << _name << std::endl;

	if (!_description.empty()) {
		std::cout << indent << "  description: " << _description << std::endl;
	}

	for (auto&& alias : _alias) {
		std::cout << indent << "  alias: " << alias << std::endl;
	}

	for (auto&& child : _child) {
		child.print();
	}
}

void Option::apply(std::string value) {
	_value = std::move(value);
}

std::string& Option::get() {
	return _value;
}

bool Option::validate() {
	for(auto& v : _validator) {
		if (!v(*this)) {
			return false;
		}
	}
	return true;
}

Option& Option::name(std::string name) {
	_name = std::move(name);
	return *this;
}

Option& Option::validator(std::function<bool(Option&)> validator) {
	_validator.push_back(std::move(validator));
	return *this;
}

Option& Option::alias(std::string alias) {
	_alias.push_back(std::move(alias));
	return *this;
}

Option& Option::description(std::string description) {
	_description = std::move(description);
	return *this;
}

Option& Option::child(Option child) {
	child._parent = this;
	_child.push_back(std::move(child));
	return *this;
}

} // namespace opt
