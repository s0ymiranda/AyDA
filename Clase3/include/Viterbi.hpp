#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "HiddenMarkov.hpp"

std::vector<std::string> dynamic_programming_gr(const HiddenMarkovModel& hmm, const std::vector<std::string>& observation) noexcept;