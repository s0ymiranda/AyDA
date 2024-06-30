#include <iostream>

#include <Solver.hpp>

using namespace std;

ostream& operator << (ostream& out, const vector<string>& v)
{
    out << "[";
    
    auto it = v.begin();
    
    if (it != v.end())
    {
        out << *it;
        ++it;
    }
    
    while (it != v.end())
    {
        out << ", " << *it;
        ++it;
    }
    
    out << "]";
    
    return out;
}

bool operator != (const vector<string>& v1, const vector<string>& v2)
{
    if (v1.size() != v2.size())
    {
        return true;
    }

    auto it1 = v1.begin();
    auto it2 = v2.begin();

    for ( ; it1 != v1.end(); ++it1, ++it2)
    {
        if (*it1 != *it2)
        {
            return true;
        }
    }

    return false;
}

void assert_equal(const vector<string>& current, const vector<string>& expected)
{
    if (expected != current)
    {
        cerr << "Test failed!\n";
        cerr << "Current: " << current << endl;
        cerr << "Expected: " << expected << endl;
        abort();
    }

    cout << "Test ok!\n";
}

struct Data
{
    static const HiddenMarkovModel speech_recognition_hmm;
    static const vector<string> sample_otter;
    static const vector<string> sample_automobile;
    static const vector<string> expected_greedy_otter;
    static const vector<string> expected_greedy_automobile;
    static const vector<string> expected_dynamic_programming_otter;
    static const vector<string> expected_dynamic_programming_automobile;
};

const HiddenMarkovModel Data::speech_recognition_hmm
{
    ProbabilityDistributionMap
    {
        make_pair("au", 0.5f), make_pair("to", 0.f), make_pair("o", 0.5f), make_pair("tter", 0.f), make_pair("mo", 0.f), make_pair("bile", 0.f)
    },

    ProbabilityMatrix
    {
        make_pair("au", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 1.f), make_pair("o", 0.f), make_pair("tter", 0.f), make_pair("mo", 0.f), make_pair("bile", 0.f) }),
        make_pair("to", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 0.f), make_pair("o", 0.f), make_pair("tter", 0.f), make_pair("mo", 1.f), make_pair("bile", 0.f) }),
        make_pair("o", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 0.f), make_pair("o", 0.f), make_pair("tter", 1.f), make_pair("mo", 0.f), make_pair("bile", 0.f) }),
        make_pair("tter", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 0.f), make_pair("o", 0.f), make_pair("tter", 0.f), make_pair("mo", 0.f), make_pair("bile", 0.f) }),
        make_pair("mo", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 0.f), make_pair("o", 0.f), make_pair("tter", 0.f), make_pair("mo", 0.f), make_pair("bile", 1.f) }),
        make_pair("bile", ProbabilityDistributionMap{ make_pair("au", 0.f), make_pair("to", 0.f), make_pair("o", 0.f), make_pair("tter", 0.f), make_pair("mo", 0.f), make_pair("bile", 0.f) })
    },

    ProbabilityMatrix
    {
        make_pair("au", ProbabilityDistributionMap{ make_pair("sound-au", 0.7f), make_pair("sound-to", 0.f), make_pair("sound-o", 0.3f), make_pair("sound-tter", 0.f), make_pair("sound-mo", 0.f), make_pair("sound-bile", 0.f) }),
        make_pair("to", ProbabilityDistributionMap{ make_pair("sound-au", 0.f), make_pair("sound-to", 0.7f), make_pair("sound-o", 0.f), make_pair("sound-tter", 0.3f), make_pair("sound-mo", 0.f), make_pair("sound-bile", 0.f) }),
        make_pair("o", ProbabilityDistributionMap{ make_pair("sound-au", 0.3f), make_pair("sound-to", 0.f), make_pair("sound-o", 0.7f), make_pair("sound-tter", 0.f), make_pair("sound-mo", 0.f), make_pair("sound-bile", 0.f) }),
        make_pair("tter", ProbabilityDistributionMap{ make_pair("sound-au", 0.f), make_pair("sound-to", 0.3f), make_pair("sound-o", 0.f), make_pair("sound-tter", 0.7f), make_pair("sound-mo", 0.f), make_pair("sound-bile", 0.f) }),
        make_pair("mo", ProbabilityDistributionMap{ make_pair("sound-au", 0.f), make_pair("sound-to", 0.f), make_pair("sound-o", 0.f), make_pair("sound-tter", 0.f), make_pair("sound-mo", 1.f), make_pair("sound-bile", 0.f) }),
        make_pair("bile", ProbabilityDistributionMap{ make_pair("sound-au", 0.f), make_pair("sound-to", 0.f), make_pair("sound-o", 0.f), make_pair("sound-tter", 0.f), make_pair("sound-mo", 0.f), make_pair("sound-bile", 1.f) }),
    }
};
const vector<string> Data::sample_otter{ "sound-o", "sound-tter" };
const vector<string> Data::sample_automobile{ "sound-o", "sound-tter", "sound-mo", "sound-bile" };
const vector<string> Data::expected_greedy_otter{ "o", "tter" };
const vector<string> Data::expected_greedy_automobile{ "o", "tter", "mo", "bile" };
const vector<string> Data::expected_dynamic_programming_otter{ "o", "tter" };
const vector<string> Data::expected_dynamic_programming_automobile{ "au", "to", "mo", "bile" };


void test_dynamic_programming_otter()
{
    cout << "Given the sound sample " << Data::sample_otter << ", when the function dynamic_programming is called, then it should return " << Data::expected_dynamic_programming_otter << endl;
    auto result = dynamic_programming(Data::speech_recognition_hmm, Data::sample_otter);
    assert_equal(result, Data::expected_greedy_otter);
}

void test_dynamic_programming_automobile()
{
    cout << "Given the sound sample " << Data::sample_automobile << ", when the function dynamic_programming is called, then it should return " << Data::expected_dynamic_programming_automobile << endl;
    auto result = dynamic_programming(Data::speech_recognition_hmm, Data::sample_automobile);
    assert_equal(result, Data::expected_dynamic_programming_automobile);
}

int main()
{

    cout << "Testing dynamic_programming\n";

    test_dynamic_programming_otter();
    test_dynamic_programming_automobile();

    cout << "Everything ok!\n";
    return EXIT_SUCCESS;
}
