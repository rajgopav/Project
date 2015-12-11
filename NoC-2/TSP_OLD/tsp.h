#ifndef PAGMO_PROBLEM_TSP_H
#define PAGMO_PROBLEM_TSP_H

#include <boost/array.hpp>
#include <vector>
#include <string>

#include "./base_tsp.h"
#include "../serialization.h"

namespace pagmo { namespace problem {

/// A static Travelling Salesman Problem
/**
 * This is a class representing the classic Travelling Salesman Problem. The problem
 * is that of finding the shortest Hamiltonian path in a weighted, bidirectional graph.
 *
 * The base_tsp::distance is thus defined as the (i,j) element of a matrix represented as
 * a std::vector<std::vector<double> >
 *
 * @author Dario Izzo (dario.izzo@gmail.com)
 * @author Annalisa Riccardi
 */

class __PAGMO_VISIBLE tsp: public base_tsp
{
    public:

        tsp();
        tsp(const std::vector<std::vector<double> >&, const base_tsp::encoding_type & = CITIES);

        /// Copy constructor for polymorphic objects (deep copy)
        base_ptr clone() const;

        const std::vector<std::vector<double> >& get_weights() const;

        /** @name Implementation of virtual methods*/
        //@{
        std::string get_name() const;
        std::string human_readable_extra() const;
        double distance(decision_vector::size_type, decision_vector::size_type) const;
        //@}

    private:
        static boost::array<int, 2> compute_dimensions(decision_vector::size_type n_cities, base_tsp::encoding_type);
        void check_weights(const std::vector<std::vector<double> >&) const;
        size_t compute_idx(const size_t i, const size_t j, const size_t n) const;

        void objfun_impl(fitness_vector&, const decision_vector&) const;
        void compute_constraints_impl(constraint_vector&, const decision_vector&) const;

        friend class boost::serialization::access;
        template <class Archive>
        void serialize(Archive &ar, const unsigned int)
        {
            ar & boost::serialization::base_object<base_tsp>(*this);
            ar & m_weights;
        }

    private:
        std::vector<std::vector<double> > m_weights;
};

}}  //namespaces

BOOST_CLASS_EXPORT_KEY(pagmo::problem::tsp)

#endif  //PAGMO_PROBLEM_TSP_H