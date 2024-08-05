#include <iostream>
#include <graphalgorithms.hpp>
#include <buildgraph.hpp>

int main()
{
    ushort subjects_num = 44;

    std::string subjects_names[] = {
                                    "Programacion 1", // 0
                                    "Calculo 10", // 1
                                    "Sistemas de Representacion", // 2
                                    "Ingenieria de Sistemas", // 3
                                    "Electiva de Formacion Integral", // 4
                                    "Programacion 2", // 5
                                    "Calculo 20", // 6
                                    "Fisica 11", // 7
                                    "Introduccion a los Procesos Quimicos", // 8
                                    "Arquitectura de Computadores", // 9
                                    "Calculo 30", // 10
                                    "Fisica 21", // 11
                                    "Mecanica Racional", // 12
                                    "Ingles", // 13
                                    "Programacion 3", // 14
                                    "Calculo 40", // 15
                                    "Estocastica 1", // 16
                                    "Elementos de Economia", // 17
                                    "Laboratorio de Fisica General", // 18
                                    "Investigacion de Operaciones", // 19
                                    "Estocastica 2", // 20
                                    "Matematicas Discretas", // 21
                                    "Matematicas Especiales", // 22
                                    "Modelado de Sistemas Fisicos", // 23
                                    "Diseño y Analisis de Algoritmos", // 24
                                    "Modelado y Simulacion", // 25
                                    "Analisis Numerico", // 26
                                    "Induccion al Servicio Comunitario", // 27
                                    "Introduccion al Control Automatico", // 28
                                    "Instrumentacion 1", // 29
                                    "Sistemas Operativos", // 30
                                    "Bases de Datos", // 31
                                    "Ingenieria del Software", // 32
                                    "Teoria de la Computacion", // 33
                                    "Servicio Comunitario", // 34
                                    "Redes de Computadores", // 35
                                    "Inteligencia Artificial", // 36
                                    "Compiladores", // 37
                                    "Electiva 1", // 38
                                    "Sistemas Computacionales", // 39
                                    "Preproyecto", // 40
                                    "Electiva 2", // 41
                                    "Electiva 3", // 42
                                    "Proyecto de Grado" // 43
                                    };

    Designar::Digraph<std::string> flowchart;
    Designar::Digraph<std::string>::Node* subjects[subjects_num];

    for (size_t i = 0; i < subjects_num; ++i)
    {
        subjects[i] = flowchart.insert_node(subjects_names[i]);
    }

    std::vector<Designar::Digraph<std::string>::Arc*> prelations;

    //Programacion 1
    prelations.push_back(flowchart.insert_arc(subjects[0], subjects[5]));

    //Calculo 10
    prelations.push_back(flowchart.insert_arc(subjects[1], subjects[6]));
    prelations.push_back(flowchart.insert_arc(subjects[1], subjects[7]));
    prelations.push_back(flowchart.insert_arc(subjects[1], subjects[8]));

    //Sistemas de Representacion
    prelations.push_back(flowchart.insert_arc(subjects[2], subjects[40]));

    //Ingenieria de Sistemas
    prelations.push_back(flowchart.insert_arc(subjects[3], subjects[40]));

    //Electiva de Formacion Integral
    prelations.push_back(flowchart.insert_arc(subjects[4], subjects[40]));

    //Programacion 2
    prelations.push_back(flowchart.insert_arc(subjects[5], subjects[9]));
    prelations.push_back(flowchart.insert_arc(subjects[5], subjects[14]));
    prelations.push_back(flowchart.insert_arc(subjects[5], subjects[25]));
    prelations.push_back(flowchart.insert_arc(subjects[5], subjects[26]));

    //Calculo 20
    prelations.push_back(flowchart.insert_arc(subjects[6], subjects[10]));
    prelations.push_back(flowchart.insert_arc(subjects[6], subjects[11]));
    prelations.push_back(flowchart.insert_arc(subjects[6], subjects[12]));

    //Fisica 11
    prelations.push_back(flowchart.insert_arc(subjects[7], subjects[11]));
    prelations.push_back(flowchart.insert_arc(subjects[7], subjects[12]));

    //Introduccion a los Procesos Quimicos
    prelations.push_back(flowchart.insert_arc(subjects[8], subjects[23]));

    //Arquitectura de Computadores
    prelations.push_back(flowchart.insert_arc(subjects[9], subjects[30]));

    //Calculo 30
    prelations.push_back(flowchart.insert_arc(subjects[10], subjects[15]));
    prelations.push_back(flowchart.insert_arc(subjects[10], subjects[16]));
    prelations.push_back(flowchart.insert_arc(subjects[10], subjects[17]));

    //Fisica 21
    prelations.push_back(flowchart.insert_arc(subjects[11], subjects[18]));

    //Mecanica Racional
    prelations.push_back(flowchart.insert_arc(subjects[12], subjects[23]));

    //Ingles
    prelations.push_back(flowchart.insert_arc(subjects[13], subjects[40]));

    //Programacion 3
    prelations.push_back(flowchart.insert_arc(subjects[14], subjects[24]));

    //Calculo 40
    prelations.push_back(flowchart.insert_arc(subjects[15], subjects[19]));
    prelations.push_back(flowchart.insert_arc(subjects[15], subjects[21]));
    prelations.push_back(flowchart.insert_arc(subjects[15], subjects[22]));
    prelations.push_back(flowchart.insert_arc(subjects[15], subjects[23]));

    //Estocastica 1
    prelations.push_back(flowchart.insert_arc(subjects[16], subjects[20]));

    //Elementos de Economia
    //prelations.push_back(flowchart.insert_arc(subjects[17], subjects[43]));

    //Laboratorio de Fisica General
    prelations.push_back(flowchart.insert_arc(subjects[18], subjects[29]));

    //Investigacion de Operaciones
    //prelations.push_back(flowchart.insert_arc(subjects[19], subjects[43]));

    //Estocastica 2
    prelations.push_back(flowchart.insert_arc(subjects[20], subjects[25]));

    //Matematicas Discretas
    prelations.push_back(flowchart.insert_arc(subjects[21], subjects[33]));
    prelations.push_back(flowchart.insert_arc(subjects[21], subjects[24]));

    //Matematicas Especiales
    prelations.push_back(flowchart.insert_arc(subjects[22], subjects[26]));
    prelations.push_back(flowchart.insert_arc(subjects[22], subjects[28]));

    //Modelado de Sistemas Fisicos
    prelations.push_back(flowchart.insert_arc(subjects[23], subjects[28]));
    prelations.push_back(flowchart.insert_arc(subjects[23], subjects[29]));

    //Diseño y Analisis de Algoritmos
    prelations.push_back(flowchart.insert_arc(subjects[24], subjects[30]));
    prelations.push_back(flowchart.insert_arc(subjects[24], subjects[31]));
    prelations.push_back(flowchart.insert_arc(subjects[24], subjects[36]));

    //Modelado y Simulacion
    //prelations.push_back(flowchart.insert_arc(subjects[25], subjects[43]));

    //Analisis Numerico
    //prelations.push_back(flowchart.insert_arc(subjects[26], subjects[43]));

    //Induccion al Servicio Comunitario
    prelations.push_back(flowchart.insert_arc(subjects[27], subjects[34]));

    //Introduccion al Control Automatico
    //prelations.push_back(flowchart.insert_arc(subjects[28], subjects[43]));

    //Instrumentacion 1
    //prelations.push_back(flowchart.insert_arc(subjects[29], subjects[43]));

    //Sistemas Operativos
    prelations.push_back(flowchart.insert_arc(subjects[30], subjects[35]));

    //Bases de Datos
    prelations.push_back(flowchart.insert_arc(subjects[31], subjects[39]));
    prelations.push_back(flowchart.insert_arc(subjects[31], subjects[40]));

    //Ingenieria del Software
    prelations.push_back(flowchart.insert_arc(subjects[32], subjects[39]));
    prelations.push_back(flowchart.insert_arc(subjects[32], subjects[40]));

    //Teoria de la Computacion
    prelations.push_back(flowchart.insert_arc(subjects[33], subjects[37]));

    //Servicio Comunitario
    //prelations.push_back(flowchart.insert_arc(subjects[34], subjects[43]));

    //Redes de Computadores
    prelations.push_back(flowchart.insert_arc(subjects[35], subjects[39]));
    prelations.push_back(flowchart.insert_arc(subjects[35], subjects[40]));

    //Inteligencia Artificial
    prelations.push_back(flowchart.insert_arc(subjects[36], subjects[39]));
    prelations.push_back(flowchart.insert_arc(subjects[36], subjects[40]));

    //Compiladores
    prelations.push_back(flowchart.insert_arc(subjects[37], subjects[39]));
    prelations.push_back(flowchart.insert_arc(subjects[37], subjects[40]));

    //Electiva 1
    prelations.push_back(flowchart.insert_arc(subjects[38], subjects[43]));

    //Sistemas Computacionales
    prelations.push_back(flowchart.insert_arc(subjects[39], subjects[43]));

    //Preproyecto
    prelations.push_back(flowchart.insert_arc(subjects[40], subjects[43]));

    //Electiva 2
    prelations.push_back(flowchart.insert_arc(subjects[41], subjects[43]));

    //Electiva 3
    prelations.push_back(flowchart.insert_arc(subjects[42], subjects[43]));

    //Proyecto de Grado
    //prelations.push_back(flowchart.insert_arc(subjects[43], subjects[43]));

    auto topological_ranks_matrix = Designar::topological_ranks(flowchart);

    ushort i = 0;
    for (auto it = topological_ranks_matrix.begin(); it != topological_ranks_matrix.end(); ++it)
    {
        std::cout << "Semestre " << ++i << ":" << std::endl;
        for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
        {
            std::cout << (*it2)->get_info() << std::endl;
        }
        std::cout << std::endl << std::endl;
    }

    Designar::DotGraph<Designar::Digraph<std::string>>().write_graph(flowchart, "flowchart.dot");

    return EXIT_SUCCESS;
}