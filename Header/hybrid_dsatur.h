#ifndef _HYBRID_DSATUR_H_
#define _HYBRID_DSATUR_H_

#include "graph_color.h"
#include "dsatur.h"
#include "tabucol.h"

using GraphColoring::GraphColor;
using GraphColoring::Dsatur;
using GraphColoring::Tabucol;

namespace GraphColoring{
    class HybridDsatur : public GraphColor {
        public: 
            /* Constructors */
            HybridDsatur() : GraphColor() { }
            HybridDsatur(map<string, vector<string> > input_graph) :GraphColor(input_graph) { } 

            /* Mutators */
            map<string,int> color();
            void set_condition(int con);

            /* Accessors */
            string get_algorithm() { return "HYBRID_DSATUR"; }
    };
}

#endif
