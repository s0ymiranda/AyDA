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
    static const HiddenMarkovModel weather_recognition_hmm;
    static const vector<string> sample_weather_1;
    static const vector<string> sample_weather_2;
    static const vector<string> sample_weather_3;
    static const vector<string> expected_dynamic_programming_weather_1;
    static const vector<string> expected_dynamic_programming_weather_2;
    static const vector<string> expected_dynamic_programming_weather_3;
};

const HiddenMarkovModel Data::weather_recognition_hmm
{
    ProbabilityDistributionMap
    {
        make_pair("Sunny", 0.3f), make_pair("Cloudy", 0.4f), make_pair("Rainy", 0.3f)    
    },

    ProbabilityMatrix
    {
        make_pair("Sunny", ProbabilityDistributionMap{ make_pair("Sunny", 0.7f), make_pair("Cloudy", 0.3f), make_pair("Rainy", 0.f) }),
        make_pair("Cloudy", ProbabilityDistributionMap{ make_pair("Sunny", 0.2f), make_pair("Cloudy", 0.6f), make_pair("Rainy", 0.2f) }),
        make_pair("Rainy", ProbabilityDistributionMap{ make_pair("Sunny", 0.), make_pair("Cloudy", 0.4f), make_pair("Rainy", 0.6f) })
    },

    ProbabilityMatrix
    {
        make_pair("Sunny", ProbabilityDistributionMap{ make_pair("temp_hot", 0.6f), make_pair("not_clear_sky", 0.4f), make_pair("humidity", 0.f) }),
        make_pair("Cloudy", ProbabilityDistributionMap{ make_pair("temp_hot", 0.1f), make_pair("not_clear_sky", 0.5f), make_pair("humidity", 0.3f) }),
        make_pair("Rainy", ProbabilityDistributionMap{ make_pair("temp_hot", 0.f), make_pair("not_clear_sky", 0.5f), make_pair("humidity", 0.5f) })
    }
};

const vector<string> Data::sample_weather_1{ "temp_hot", "not_clear_sky", "humidity"};
const vector<string> Data::sample_weather_2{ "temp_hot", "not_clear_sky", "humidity", "temp_hot", "humidity" };
const vector<string> Data::sample_weather_3{"humidity", "not_clear_sky", "humidity", "temp_hot", "not_clear_sky", "humidity" };
const vector<string> Data::expected_dynamic_programming_weather_1{ "Sunny" ,"Cloudy", "Cloudy"};
const vector<string> Data::expected_dynamic_programming_weather_2{ "Sunny", "Cloudy", "Cloudy", "Cloudy", "Cloudy" };
const vector<string> Data::expected_dynamic_programming_weather_3{ "Rainy", "Rainy", "Rainy", "Cloudy", "Cloudy","Cloudy"};


void test_dynamic_programming_1()
{
    cout << "Given the samples " << Data::sample_weather_1 << ", when the function dynamic_programming is called, then it should return " << Data::expected_dynamic_programming_weather_1 << endl;
    auto result = dynamic_programming(Data::weather_recognition_hmm, Data::sample_weather_1);
    assert_equal(result, Data::expected_dynamic_programming_weather_1);
}

void test_dynamic_programming_2()
{
    cout << "Given the samples " << Data::sample_weather_2 << ", when the function dynamic_programming is called, then it should return " << Data::expected_dynamic_programming_weather_2 << endl;
    auto result = dynamic_programming(Data::weather_recognition_hmm, Data::sample_weather_2);
    assert_equal(result, Data::expected_dynamic_programming_weather_2);
}

void test_dynamic_programming_3()
{
    cout << "Given the samples " << Data::sample_weather_3 << ", when the function dynamic_programming is called, then it should return " << Data::expected_dynamic_programming_weather_2 << endl;
    auto result = dynamic_programming(Data::weather_recognition_hmm, Data::sample_weather_3);
    assert_equal(result, Data::expected_dynamic_programming_weather_3);
}

int main()
{

    cout << "Testing dynamic_programming\n";

    test_dynamic_programming_1();
    test_dynamic_programming_2();
    test_dynamic_programming_3();

    cout << "Everything ok!\n";
    return EXIT_SUCCESS;
}
