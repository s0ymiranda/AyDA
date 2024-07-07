#include <Solver.hpp>
#include <limits>

std::vector<std::string> dynamic_programming(const HiddenMarkovModel& hmm, const std::vector<std::string>& observations) noexcept
{
    // Grid of probabilities with previous states.
    std::vector<std::unordered_map< /* current state */ std::string, /* Probability with back pointer */ std::pair< /* probability */ float, /* previous state */ std::string>>> grid{observations.size()};

    for (const std::string& s: hmm.possible_states)
    {
        grid[0][s] = std::make_pair(hmm.start_probabilities.at(s) * hmm.emission_probabilities.at(s).at(observations[0]), "");
    }

    for (size_t t = 1; t < observations.size(); ++t)
    {
        for (const std::string& s: hmm.possible_states)
        {
            float emission_prob = hmm.emission_probabilities.at(s).at(observations[t]);

            float max_transition_probability = std::numeric_limits<float>::lowest();
            std::string best_previous_state{};

            for (const std::string& ps: hmm.possible_states)
            {
                float p = grid[t - 1][ps].first * hmm.transition_probabilities.at(ps).at(s) * emission_prob;
                if (p > max_transition_probability)
                {
                    max_transition_probability = p;
                    best_previous_state = ps;
                }
            }

            grid[t][s] = std::make_pair(max_transition_probability, best_previous_state);
        }
    }

    auto it = hmm.possible_states.begin();
    std::string max_end_state{*it};
    ++it;
    const auto& grid_end = grid[grid.size() - 1];
    float max_end_probability = grid_end.at(max_end_state).first;
    
    while (it != hmm.possible_states.end())
    {
        if (grid_end.at(*it).first > max_end_probability)
        {
            max_end_probability = grid_end.at(*it).first;
            max_end_state = *it;
        }

        ++it;
    }

    std::vector<std::string> path_states{observations.size()};
    std::string last_state = max_end_state;
    
    auto pit = path_states.rbegin();

    for (size_t i = observations.size(); i > 0; --i, ++pit)
    {
        *pit = last_state;
        last_state = grid[i - 1][last_state].second;
    }

    return path_states;
}