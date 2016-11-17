#pragma once

#include <string>
#include <ostream>

#define ALPHABET_SIZE 26

namespace atod
{

class trie
{
public:
    trie();
    ~trie();

    void add ( const std::string& str );

    size_t count ( const std::string& str ) const;

    inline bool exists ( const std::string& str ) const
    {
        return ( count ( str ) > 0 );
    }

    void print ( std::ostream& dest ) const;;

private:
    class node
    {
    public:
        node ( char c );
        ~node();

        char character_;
        size_t count_;
        node* children_[ALPHABET_SIZE];        
    };

    static int getCharIdx ( char c );

    void internalPrint ( const node* n, std::string& prev, std::ostream& dest ) const;

    node root_;
};

}

