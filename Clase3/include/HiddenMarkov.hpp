#pragma once

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

// Alias for a string set
using SSet = std::unordered_set<std::string>;

// Alias for probability distribution mapping for string values
using ProbabilityDistributionMap = std::unordered_map<std::string, float>;

// Alias for a probability matrix
using ProbabilityMatrix = std::unordered_map<std::string, ProbabilityDistributionMap>;

/** A representation of a Hidden Markov Model.
 * 
 * A representation of a Hidden Markov Model consisting of:
 * 
 * - A set of possible states.
 * - The initial probabilities for the states.
 * - The transition probabilities between the states.
 * - The emission probabilities for the states and observations.
 */
struct HiddenMarkovModel
{
  HiddenMarkovModel(const ProbabilityDistributionMap& sp, const ProbabilityMatrix& tp, const ProbabilityMatrix& ep) noexcept;

  SSet possible_states;
  ProbabilityDistributionMap start_probabilities;
  ProbabilityMatrix transition_probabilities;
  ProbabilityMatrix emission_probabilities;
};

std::ostream& operator << (std::ostream& out, const SSet& ss);

std::ostream& operator << (std::ostream& out, const std::pair<std::string, float>& p);

std::ostream& operator << (std::ostream& out, const ProbabilityDistributionMap& pdm);

std::ostream& operator << (std::ostream& out, const std::pair<std::string, ProbabilityDistributionMap>& p);

std::ostream& operator << (std::ostream& out, const ProbabilityMatrix& pm);

std::ostream& operator << (std::ostream& out, const HiddenMarkovModel& hmm);