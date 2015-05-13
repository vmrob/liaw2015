#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace opt {

class Option {
public:
	Option(Option* parent = nullptr);
	Option(const Option&) = default;
	Option(Option&&) = default;

	size_t getDepth();
	void print();

	void apply(std::string value);
	std::string& get();

	bool validate();

	// attributes

	Option& name(std::string name);
	Option& validator(std::function<bool(Option&)> validator);
	Option& alias(std::string alias);
	Option& description(std::string description);
	Option& child(Option child);

private:
	Option* _parent;
	std::string _value;

	// attributes
	std::string _name;
	std::string _description;
	std::vector<std::string> _alias;
	std::vector<std::function<bool(Option&)>> _validator;
	std::vector<Option> _child;
};

#define CONFIG_ATTRIBUTE(attr_name) \
	template <typename ... Args> \
	auto attr_name(Args&& ... args) { \
		return Option().attr_name(std::forward<Args>(args)...); \
	}

CONFIG_ATTRIBUTE(name);

} // namespace opt
