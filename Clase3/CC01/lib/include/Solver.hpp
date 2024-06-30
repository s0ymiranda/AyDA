#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include <HiddenMarkovModel.hpp>

std::vector<std::string> dynamic_programming(const HiddenMarkovModel& hmm, const std::vector<std::string>& observation) noexcept;