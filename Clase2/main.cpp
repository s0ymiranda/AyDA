#include "utils.hpp"
void MDPValueIteration();
int main()
{
    MDPValueIteration();
    return 0;
}

void MDPValueIteration()
{
    float delta = INFINITY;
    const float theta = 0.1;
    const unsigned short num_iterations = 100;

    std::vector<float> values(NUM_STATES, 0.0), policy(NUM_STATES, 0.0);

    for (size_t stop = 0; delta >= theta && stop < num_iterations; stop++)
    {
        delta = 0;

        for (size_t s = 0; s < NUM_STATES; s++)
        {
            float v = values[s];
            std::vector<float> q(NUM_ACTIONS,0);

            for (size_t a = 0; a < NUM_ACTIONS; a++)
            {
                for (size_t s_prime = 0; s_prime < p.at(s).at(Action(a)).size(); s_prime++)
                {

                    q[a] += std::get<1>((p.at(s)).at(Action(a))[s_prime])*(std::get<2>((p.at(s)).at(Action(a))[s_prime]) + GAMMA * values[std::get<0>((p.at(s)).at(Action(a))[s_prime])]);
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

    for (size_t s = 0; s < NUM_STATES; s++)
    {
        std::cout << "State " << s << " value: " << values[s] << " policy: " << policy[s] << std::endl;
    }

}