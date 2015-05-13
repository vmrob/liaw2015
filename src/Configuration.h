#pragma once

#include <initializer_list>
#include <vector>

namespace opt {

class Option;

class Configuration {
public:
	Configuration(std::initializer_list<Option> options);

	void print();

private:
	std::vector<Option> _options;
};

} // namespace opt
