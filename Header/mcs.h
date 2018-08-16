#ifndef _MCS_H_
#define _MCS_H_

#include "graph_color.h"

using GraphColoring::GraphColor;

namespace GraphColoring{
    class Mcs : public GraphColor {
        public: 
            Mcs() : GraphColor() {}
            Mcs(map<string, vector<string> > input_graph) : GraphColor(input_graph) {} 
            map<string,int> color();
            string get_algorithm() { return "MCS"; }

            void set_condition(int con) { }
    };
}

#endif
