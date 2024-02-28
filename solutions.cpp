//Ethan Escalante
//James Togher

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


int maxDepth(list p){
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

if(is_atom(p)){
    return 1;
}

return std::max( maxDepth(car(p)) + 1, maxDepth(cdr(p)));

}


list everyOtherAtom(list p) {
// p is a list with an even number of atoms, like () or (a b c d).
// p will NOT be a nested list, an individual atom, or a list with
//   an odd number of elements.

// The first atom in p is at position 1. The second atom is at position 2, etc.

// This function creates and returns a list that consists
// of atoms whose positions in p are odd numbers.

// For example:
// p is (a b c d e f)
// The position of a is 1, of c is 3, and of e is 5. Therefore,
// everyOtherAtom should return (a c e)


if(is_null(p)){
    return p;
}

return append(cons(car(p), null()), everyOtherAtom(cdr(cdr(p))));

}


bool memberAtLevel(list p, list q, int n) {
// p is a recursive list, but is not an atom
// q is an atom
// n >= 1

// Does p have an atom at level n that is equal to q?
// The outermost level is level 1, and the level
// increments as lists nest within it.

// Example 1:
// p = ( a b c )
// q = b
// n = 1
// memberAtLevel(p, q, n) should return true because there is
// an atom in p that is equal to q and is at level 1. This
// function should return false if n contains anything other than 1.

// Example 2:
// p = ( a b c (c (d) e) (((f))) )
// q = f
// n = 4
// memberAtLevel(p, q, n) should return true as f is at level 4 in p.

    if(is_null(p)){
        return false;
    }

    if (is_atom(car(p))) {
        if(n == 1) {
            if (eq(car(p), q)) {
                return true;
            }
        }else if(!is_null(cdr(p))){ //probably not needed
            return memberAtLevel(cdr(p), q, n);
        }

        return memberAtLevel(cdr(p),q, n);
    }

    return memberAtLevel(car(p), q, n-1) || memberAtLevel(cdr(p), q, n);
    //checking if car(p) OR cdr(p) is true or false, as long as one of these are true, the elements match up and the n decrements to one (base level)



}