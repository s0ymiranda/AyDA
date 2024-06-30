#include <algorithm>
#include <iostream>

#include <HiddenMarkovModel.hpp>

HiddenMarkovModel::HiddenMarkovModel(const ProbabilityDistributionMap& sp, const ProbabilityMatrix& tp, const ProbabilityMatrix& ep) noexcept
    : possible_states{}, start_probabilities{sp}, transition_probabilities{tp}, emission_probabilities{ep}
{
    std::transform(start_probabilities.begin(), start_probabilities.end(), std::inserter(possible_states, possible_states.begin()), [](const auto& p) { return p.first; });
}

std::ostream& operator << (std::ostream& out, const SSet& ss)
{
    out << "[";

    auto it = ss.begin();

    if (it != ss.end())
    {
        out << *it;
        ++it;
    }

    for ( ; it != ss.end(); ++it)
    {
        out << ", " << *it;
    }

    out << "]";

    return out;
}

std::ostream& operator << (std::ostream& out, const std::pair<std::string, float>& p)
{
    out << p.first << ": " << p.second;
    return out;
}

std::ostream& operator << (std::ostream& out, const ProbabilityDistributionMap& pdm)
{
    out << "{";

    auto it = pdm.begin();

    if (it != pdm.end())
    {
        out << *it;
        ++it;
    }

    for ( ; it != pdm.end(); ++it)
    {
        out << ", " << *it;
    }

    out << "}";

    return out;
}

std::ostream& operator << (std::ostream& out, const std::pair<std::string, ProbabilityDistributionMap>& p)
{
    out << p.first << ": " << p.second;
    return out;
}

std::ostream& operator << (std::ostream& out, const ProbabilityMatrix& pm)
{
    out << "{";

    auto it = pm.begin();

    if (it != pm.end())
    {
        out << *it;
        ++it;
    }

    for ( ; it != pm.end(); ++it)
    {
        out << ",\n" << *it;
    }

    out << "}";

    return out;
}

std::ostream& operator << (std::ostream& out, const HiddenMarkovModel& hmm)
{
    out << "Possible states: " << hmm.possible_states << std::endl;
    out << "Start Probabilities: " << hmm.start_probabilities << std::endl;
    out << "Transition Probabilities: " << hmm.transition_probabilities << std::endl;
    out << "Emission Probabilities: " << hmm.emission_probabilities;

    return out;
}