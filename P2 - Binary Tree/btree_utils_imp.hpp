/**
 * CopyRight F. J. Madrid-Cuevas <fjmadrid@uco.es>
 *
 * Sólo se permite el uso de este código en la docencia de las asignaturas sobre
 * Estructuras de Datos de la Universidad de Córdoba.
 *
 * Está prohibido su uso para cualquier otro objetivo.
 */
#pragma once

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <queue>

#include "btree_utils.hpp"

template<class T>
int compute_height (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    int height = 0;
    //TODO

    // Arbol vacio
    if( t->is_empty() ){
        return -1;
    }
    // Calcular alturas de ambos hijos
    int leftHeight = compute_height<T>(t->left());
    int rightHeight = compute_height<T>(t->right());

    if( rightHeight > leftHeight) {
        height = rightHeight + 1;
    }
    else{
        height = leftHeight + 1;
    }
    //
    return height;
}

template<class T>
size_t compute_size (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    size_t ret_val = 0;
    //TODO
    if( !(t->is_empty()) ){
        ret_val += compute_size<int>( t->left() );
        ret_val += compute_size<int>( t->right() );

        ret_val++;
    }
    //
    return ret_val;
}

template <class T, typename Processor>
bool
prefix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    if( !(tree->is_empty()) ){
            retVal = p(tree->item());

            retVal = retVal && prefix_process<int>(tree->left(), p);
            retVal = retVal && prefix_process<int>(tree->right(), p);
    }
    //
    return retVal;
}

template <class T, class Processor>
bool
infix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    if( !(tree->is_empty()) ){
        retVal = infix_process<int>(tree->left(), p);
        retVal = retVal && p(tree->item());
        retVal = retVal && infix_process<int>(tree->right(), p);

    }
    //
    return retVal;
}

template <class T, class Processor>
bool
postfix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;
    //TODO
    if( !(tree->is_empty()) ){
        retVal = postfix_process<int>(tree->left(), p);
        retVal = retVal && postfix_process<int>(tree->right(), p);
        retVal = retVal && p(tree->item());

    }
    //
    return retVal;
}


template <class T, class Processor>
bool
breadth_first_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool go_on = true;
    //TODO
    typename BTree<T>::Ref subtree;
        std::queue<typename BTree<T>::Ref> q;
        q.push(tree); //Encolamos el árbol antes de empezar

        while (!q.empty() && go_on)
        {
            subtree = q.front();      //Igualamos al subtree al frente de la cola
            if (!subtree->is_empty()) //Mientras que el subtree no esté vacío, entramos en la condición
            {
                go_on = p(subtree->item());
                q.push(subtree->left());  //Metemos el árbol izquierdo en la cola
                q.push(subtree->right()); //Metemos el árbol derecho en la cola
            }
            q.pop();
        }
    //
    return go_on;
}

template <class T>
std::ostream&
print_prefix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a prefix_process to process the tree with this lambda.
    //Remenber: the lambda must return true.

    //
    return out;
}

template <class T>
std::ostream&
print_infix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a infix_process to process the tree with this lambda.
    //Remenber: the lambda must return true.

    //
    return out;
}

template <class T>
std::ostream&
print_postfix(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a postfix_process to process the tree with this lambda.
    //Remenber: the lambda must return true.

    //
    return out;
}

template <class T>
std::ostream&
print_breadth_first(std::ostream& out, typename BTree<T>::Ref tree)
{
    //TODO
    //You must create a lambda function with a parameter to be printed and
    //  use a breadth_first_process to process the tree with this lambda.
    //Remenber: the lambda must return true.

    //
    return out;
}

template <class T>
bool search_prefix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with in the prefix_process.
    //Remenber: Also, the lambda must update the count variable and
    //must return True/False.

    //
    return found;
}

template <class T>
bool search_infix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with in the infix_process.
    //Remenber: Also, the lambda must update the count variable and
    //must return True/False.

    //
    return found;
}

template <class T>
bool search_postfix(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with in the postfix_process.
    //Remenber: Also, the lambda must update the count variable and
    //must return True/False.

    //
    return found;
}

template <class T>
bool search_breadth_first(typename BTree<T>::Ref tree, const T& it, size_t& count)
{
    bool found = false;
    count = 0;
    //TODO
    //You must create a lambda function with a parameter to compare it to the
    // value of the element to be searched for.
    // Use the lambda with in the breadth_first_process.
    //Remenber: Also, the lambda must update the count variable and
    //must return True/False.

    //
    return found;
}


template<class T>
bool check_btree_in_order(typename BTree<T>::Ref const& tree)
{
    bool ret_val = true;
    //TODO
    if( !(tree->is_empty()) ){
        T last_item;
        bool first_item = true;

        //Función lambda
        auto p = [&](T const& v) -> bool {
            bool ret_val = true;
            if (first_item) {
                first_item = false;
                last_item = v;
            }
            else{
                ret_val = last_item < v;
                last_item = v;
            }

            return ret_val;
        };

        //Utilizar infix_process pasándole como Processor la función lambda
        ret_val = infix_process<T>(tree, p);
    }
    //
    return ret_val;
}

template<class T>
bool has_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));    
    bool ret_val = false;
    //TODO
    typename BTree<T>::Ref current = tree;

    while (!current->is_empty() && !ret_val){
        if (current->item() == v){
            ret_val = true;
        }
        else{
            if(current->item() > v){
                current = current->left();
            }
            else{
                current = current->right();
            }
        }
    }
    //
    return ret_val;
}

template <class T>
void insert_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));
    //TODO
    typename BTree<T>::Ref current;

    bool insertado = false;

    if(tree->is_empty()){
        //current = BTree<T>::create(v);
        tree->create_root(v);
    }
    else if(!has_in_order(tree,v)){
        current = BTree<T>:: create(v);

        if(tree->item()>v){
            tree->set_left(current);
            insertado=true;
            tree = tree->left();
        }
        else if(tree->item()<v){
            tree->set_right(current);
            insertado=true;
            tree = tree->right();
        }
    }
    //
    assert(has_in_order<T>(tree, v));
}
