#include "utils.hpp"
int main()
{
    float delta = INFINITY;
    const unsigned short num_states = 15;
    const unsigned short num_actions = 4;
    const float gamma = 0.9;
    const float theta = 0.1;
    const unsigned short num_iterations = 100;

    std::vector<float> values(num_states, 0.0), policy(num_states, 0.0);

    for (size_t stop = 0; delta >= theta && stop < num_iterations; stop++)
    {
        delta = 0;

        for (size_t s = 0; s < num_states; s++)
        {
            float v = values[s];
            std::vector<float> q(num_actions,0);

            for (size_t a = 0; a < num_actions; a++)
            {
                for (size_t s_prime = 0; s_prime < p.at(s).at(Action(a)).size(); s_prime++)
                {

                    q[a] += std::get<1>((p.at(s)).at(Action(a))[s_prime])*(std::get<2>((p.at(s)).at(Action(a))[s_prime]) + gamma * values[std::get<0>((p.at(s)).at(Action(a))[s_prime])]);
                }
            }

            float val = q[0];
            size_t idx = 0;
            for (size_t i = 0; i < q.size(); i++)
            {
                if(val < q[i])
                {
                    val = q[i];
                    idx = i;
                }
            }
            values[s] = val;
            policy[s] = idx;
            delta = std::max(delta, std::abs(values[s] - v));
        }
    }

    for (size_t s = 0; s < num_states; s++)
    {
        std::cout << "State " << s << " value: " << values[s] << " policy: " << policy[s] << std::endl;
    }

    return 0;
}