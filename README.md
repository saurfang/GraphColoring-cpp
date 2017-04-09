## Graph Coloring library 

**Please note, currently the algorithms Hybrid and lmXRLF need additional testing. All other algorithms have been tested and are working.**

This system uses a map graph representation as input

    map<string,vector<string> > input_graph;

Each node is a unique string, and maps to a `vector<string>` that represent that node's neighbors. If your system uses a unique hash string you can use that directly, if your nodes are numbered then you can use `std::to_string()` to convert those id's to unique strings directly.

This input graph is then passed to an algorithm object, such as an object for the DSATUR algorithm shown here (Note: there are more algorithms listed below):

    Dsatur* algorithm = new Dsatur(input_graph);

this creates a new DSATUR algorithm object that is loaded with your graph. If you need to update or modify the graph after your algorithm object has been constrcuted, you can do so using the `modify_graph(string, vector<string>)` function.

    vector<string> neighbors = {"Neighbor 1", "Neighbor 2", "Neighbor 3"};
    algorithm->modify_graph("New Node", neighbors);

If the input `string` node already exists in the graph, it will update the neighbors of that node using the input `vector<string>`. If the input `string` node doesn't already exist in the graph it is added to the graph with the list of neighbors input via the `vector<string>`.

You can also replace the entire graph in your algorithm with a new graph by using the `set_graph(map<string, vector<string>>)` function, which will replace the loaded graph with the newly input graph.

Once your algorithm has been loaded with the proper graph, you simply need to call the `color()` function on your algorithm object to color it.

    algorithm->color();

In order to aid in validating the colorings that are created using these algorithms, we also provide a `verify()` function that will perform a full check of the graph to ensure that no two adjacent nodes share the same color.

    algorithm->verify();

Some of the algorithms that are available here are heuristics with variable conditions. While the algorithm objects are constructed with a reasonable default value, you can modifiy the condition variable of any algorithms that have them with a `set_condition(int)` function.
    
    algorithm->set_condition(new_value);

The algorithm object has an internal flag to checking if the graph has been colored, and this flag is reset every time the underlying graph is reset or modified. You should check this flag before you call the `color()` function to make sure that the color map you receive is valid.

    algorithm->is_colored();

Once you have colored your graph, there are a few functions for getting important values:

    algorithm->print_chromatic(); //prints the number of colors required to color your graph
    algorithm->print_coloring(); //prints each node (by name) and it's color (int)
    algorithm->find_max_color(); //returns the highest color (numbered from 0, is equal to the chromatic number - 1)

You can also write the entire graph into a .dot file using the `write_graph(string filename` function, where the file will be named after the input string (if no name is provided it will be named `colored_graph.dot`)

    algorithm->write_graph(string filename); //generates a .dot file named after the input string

This package was refactored to be more easily extended. I encourage you to write new coloring algorithms utilizing this code as a base, and simply ask that you include this repo's LICENSE with any of your code, and cite/acknowledge this repo in any publications. If you do utilize this code in a publication or project, or you would like to contribute a new algorithm please reach out to me (brrcrites@gmail.com).

## Available Algorithms: 

Five coloring algorithms are currently provided in this package (See reference papers for descriptions):

- DSATUR (New Methods to Color the Vertices of a Graph - Brelaz et al.) -- `Dsatur`
- MCS (Register Allocation via Coloring of Chordal Graphs - Magno et al.) -- `Mcs`
- lmXRLF (Efficient Coloring of a Large Spectrum of Graphs - Kirovski et al.) -- `Lmxrlf`
- Hybrid TabuCol (Custom, based on Efficient Coloring... - Kirovski et al.) -- `Hybrid`
- Hybrid DSATUR (Custom, based on Efficient Coloring... - Kirovski et al.) -- `HybridDsatur`

Additionally, there is a k-coloring algorithm that is accessible, and used internally within other algorithms:

- TabuCol (Using Tabu Search Techniques for Graph Coloring - Hertz et al.) -- `Tabucol`

## Running Tests/Test Sets:
You can test that the program is running correctly by running the following command, which will build a graph for the wheel test, run the DSATUR coloring algorithm, then print the chromatic number.

    make test

You can run specific sets of tests with each graph coloring algorithm by specifying which test set test to run by editing the TEST make variable (by default the main will run the test/test set with DSATUR).

    make test TEST="group_name"

Where `group_name` is the name of a test group from this list:

- all (runs every test)
- fullins
- insertions
- anna
- ash
- david
- dsjc
- dsjr
- flat
- fpsol
- games
- homer
- huck
- inithx
- jean
- le
- miles
- mug
- mulsol
- myciel
- queen
- r125
- r250
- r1000
- rtotal
- school
- will
- zeroin
- bondymurty
- chvatal
- cube
- dodeca
- grotzsch
- grunbaum
- icosa
- kuratowski
- india
- mycielski
- octa
- petersen
- ramsey
- tetra
- wheel

## Adding Tests:

You can also add tests to the `Tests/` directory that are in the following formats:

Edge List Input File Format:

    c FILE: <filename.col>
    c SOURCE: <source>
    c DESCRIPTION: <description>

    p edge <|#nodes|> <|#edges|>
    e <source> <sink>

Edge Matrix Input File Format:

    <|#nodes|>
    <|#nodes|x|#nodes| matrix>

    1 indicates an edge between column node and row node
    0 indicates a lack of an edge

Once you have added tests, you can give them a group handle in the `Tests/test_cases.mk` file, and then register them in the if/else tree under the "test" command.

