#include<cstring>
#include <algorithm>
#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}

list append(list p, list q){
    if(is_null(p)) {
        return q;
    }
    return cons(car(p), append(cdr(p), q));

}

int numAtoms(list p){
    if(is_null(p)){
        return 0;
    }

    if(is_atom(car(p))){
        return 1 + numAtoms(cdr(p));
    }

    return numAtoms(cdr(p)) + numAtoms(car(p));

}

list reverseTopLevel(list p) {
// Reverses the nodes of p at the top level.
    if( is_null(p) )
        return null();
    return append( reverseTopLevel( cdr(p) ), cons( car(p), null() ) );
}


int max_depth(list p){
// Here is the definition of depth for recursive lists.
// Intuitively, the depth of a list is the maximum
// number of levels of the list.

// Here is a more formal definition:
//       when p is a null list, its depth is 0
//       when p is an atom, its depth is 1
//       otherwise, the depth of p is the larger of
//            the depth of its car plus one, and
//            the depth of its cdr.

// You should feel free to #include <algorithm> and use the
// "max" STL function, which will compute the max of any
// 2 arguments for which the "less-than" operation is defined
// Example: std::max(2, 3) returns 3.

if(is_null(p)){
    return 0;
}

if(!is_null(car(p))){
    return 1 + max_depth(cdr(p));
}

std::max(max_depth(car(p)), max_depth(cdr(p)));

return max_depth(cdr(p));

}
