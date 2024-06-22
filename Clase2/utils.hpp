#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <ctime>

enum class Action
{
    UP,
    RIGTH,
    LEFT,
    DOWN
};

using State = unsigned long;
const float PROB = float(1)/float(3);
                         //State //Probability //Reward
using Transition = std::tuple<State, float, float>;

const std::unordered_map<State, std::unordered_map<Action, std::vector<Transition>>>& p =
{
     //Current State (s) //Action //Transition to a state (s')
    {0, {{Action::UP, {{0, PROB, 0}, {0, PROB, 0}, {1, PROB, 0}}},
         {Action::RIGTH, {{1, PROB, 0}, {0, PROB, 0}, {5, PROB, 0}}},
         {Action::LEFT, {{0, PROB, 0}, {5, PROB, 0}, {0, PROB, 0}}},
         {Action::DOWN, {{5, PROB, 0}, {1, PROB, 0}, {0, PROB, 0}}}}},

    {1, {{Action::UP, {{1, PROB, 0}, {0, PROB, 0}, {2, PROB, 0}}},
         {Action::RIGTH, {{2, PROB, 0}, {1, PROB, 0}, {6, PROB, -1}}},
         {Action::LEFT, {{0, PROB, 0}, {6, PROB, -1}, {1, PROB, 0}}},
         {Action::DOWN, {{6, PROB, -1}, {2, PROB, 0}, {0, PROB, 0}}}}},

    {2, {{Action::UP, {{2, PROB, 0}, {1, PROB, 0}, {3, PROB, 0}}},
         {Action::RIGTH, {{3, PROB, 0}, {2, PROB, 0}, {7, PROB, -1}}},
         {Action::LEFT, {{1, PROB, 0}, {7, PROB, -1}, {2, PROB, 0}}},
         {Action::DOWN, {{7, PROB, -1}, {3, PROB, 0}, {1, PROB, 0}}}}},

    {3, {{Action::UP, {{3, PROB, 0}, {2, PROB, 0}, {4, PROB, -1}}},
         {Action::RIGTH, {{4, PROB, -1}, {3, PROB, 0}, {8, PROB, 0}}},
         {Action::LEFT, {{2, PROB, 0}, {8, PROB, 0}, {3, PROB, 0}}},
         {Action::DOWN, {{8, PROB, 0}, {4, PROB, -1}, {2, PROB, 0}}}}},

    {4, {{Action::UP, {{4, PROB, -1}, {4, PROB, -1}, {4, PROB, -1}}},
         {Action::RIGTH, {{4, PROB, -1}, {4, PROB, -1}, {4, PROB, -1}}},
         {Action::LEFT, {{4, PROB, -1}, {4, PROB, -1}, {4, PROB, -1}}},
         {Action::DOWN, {{4, PROB, -1}, {4, PROB, -1}, {4, PROB, -1}}}}},

    {5, {{Action::UP, {{0, PROB, 0}, {5, PROB, 0}, {6, PROB, -1}}},
         {Action::RIGTH, {{6, PROB, -1}, {0, PROB, 0}, {10, PROB, 0}}},
         {Action::LEFT, {{5, PROB, 0}, {10, PROB, 0}, {0, PROB, 0}}},
         {Action::DOWN, {{10, PROB, 0}, {6, PROB, -1}, {5, PROB, 0}}}}},

    {6, {{Action::UP, {{6, PROB, -1}, {6, PROB, -1}, {6, PROB, -1}}},
         {Action::RIGTH, {{6, PROB, -1}, {6, PROB, -1}, {6, PROB, -1}}},
         {Action::LEFT, {{6, PROB, -1}, {6, PROB, -1}, {6, PROB, -1}}},
         {Action::DOWN, {{6, PROB, -1}, {6, PROB, -1}, {6, PROB, -1}}}}},

    {7, {{Action::UP, {{7, PROB, -1}, {7, PROB, -1}, {7, PROB, -1}}},
         {Action::RIGTH, {{7, PROB, -1}, {7, PROB, -1}, {7, PROB, -1}}},
         {Action::LEFT, {{7, PROB, -1}, {7, PROB, -1}, {7, PROB, -1}}},
         {Action::DOWN, {{7, PROB, -1}, {7, PROB, -1}, {7, PROB, -1}}}}},

    {8, {{Action::UP, {{3, PROB, 0}, {7, PROB, -1}, {9, PROB, 0}}},
         {Action::RIGTH, {{9, PROB, 0}, {3, PROB, 0}, {13, PROB, 0}}},
         {Action::LEFT, {{7, PROB, -1}, {13, PROB, 0}, {3, PROB, 0}}},
         {Action::DOWN, {{13, PROB, 0}, {9, PROB, 0}, {7, PROB, -1}}}}},

    {9, {{Action::UP, {{4, PROB, -1}, {8, PROB, 0}, {9, PROB, 0}}},
          {Action::RIGTH, {{9, PROB, 0}, {4, PROB, -1}, {14, PROB, 1}}},
          {Action::LEFT, {{8, PROB, 0}, {14, PROB, 1}, {4, PROB, -1}}},
          {Action::DOWN, {{14, PROB, 1}, {9, PROB, 0}, {8, PROB, 0}}}}},

    {10, {{Action::UP, {{5, PROB, 0}, {10, PROB, 0}, {11, PROB, 0}}},
          {Action::RIGTH, {{13, PROB, 0}, {5, PROB, 0}, {10, PROB, 0}}},
          {Action::LEFT, {{10, PROB, 0}, {10, PROB, 0}, {5, PROB, 0}}},
          {Action::DOWN, {{10, PROB, 0}, {11, PROB, 0}, {10, PROB, 0}}}}},

    {11, {{Action::UP, {{6, PROB, -1}, {10, PROB, 0}, {12, PROB, 0}}},
          {Action::RIGTH, {{12, PROB, 0}, {6, PROB, -1}, {11, PROB, 0}}},
          {Action::LEFT, {{10, PROB, 0}, {11, PROB, 0}, {6, PROB, -1}}},
          {Action::DOWN, {{11, PROB, 0}, {12, PROB, 0}, {10, PROB, 0}}}}},

    {12, {{Action::UP, {{0, PROB, 0}, {0, PROB, 0}, {1, PROB, 0}}},
          {Action::RIGTH, {{13, PROB, 0}, {7, PROB, -1}, {12, PROB, 0}}},
          {Action::LEFT, {{11, PROB, 0}, {12, PROB, 0}, {7, PROB, -1}}},
          {Action::DOWN, {{12, PROB, 0}, {13, PROB, 0}, {11, PROB, 0}}}}},

    {13, {{Action::UP, {{8, PROB, 0}, {12, PROB, 0}, {14, PROB, 1}}},
          {Action::RIGTH, {{14, PROB, 1}, {8, PROB, 0}, {13, PROB, 0}}},
          {Action::LEFT, {{12, PROB, 0}, {12, PROB, 0}, {8, PROB, 0}}},
          {Action::DOWN, {{13, PROB, 0}, {14, PROB, 1}, {12, PROB, 0}}}}},

    {14, {{Action::UP, {{14, PROB, 1}, {14, PROB, 1}, {14, PROB, 1}}},
          {Action::RIGTH, {{14, PROB, 1}, {14, PROB, 1}, {14, PROB, 1}}},
          {Action::LEFT, {{14, PROB, 1}, {14, PROB, 1}, {14, PROB, 1}}},
          {Action::DOWN, {{14, PROB, 1}, {14, PROB, 1}, {14, PROB, 1}}}}},
};