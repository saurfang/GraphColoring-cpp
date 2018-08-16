#ifndef _HYBRID_H_
#define _HYBRID_H_

#include "graph_color.h"
#include "lmxrlf.h"
#include "tabucol.h"

using GraphColoring::GraphColor;
using GraphColoring::Lmxrlf;
using GraphColoring::Tabucol;

namespace GraphColoring{
    class Hybrid : public GraphColor {
        private: 
            int condition;
            map< string,vector<string> > get_subgraph(map< string,int > coloring);
        public: 
            Hybrid() : GraphColor() { this->condition = 0; }
            Hybrid(map<string,vector<string> > input_graph) : GraphColor(input_graph) { this->condition = 0; } 
            Hybrid(map<string,vector<string> > input_graph, int con) : GraphColor(input_graph) { this->condition = con; } 
            map<string,int> color();
            void set_condition(int con) { condition = con; }
            string get_algorithm() { return "HYBRID"; }
    };
}

#endif
