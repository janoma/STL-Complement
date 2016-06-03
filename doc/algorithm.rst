Algorithm
=========

Functions that, in the same spirit of the STL, complement the ``<algorithm>``
header.

.. cpp:namespace:: stdc

.. cpp:function:: template <typename T, typename Compare = stdc::less<T>, typename... Rest> \
                  constexpr bool is_sorted(T first, T second, Rest... rest)

   Checks if the elements ``[first,second,rest...]`` are sorted in
   non-descending order according to the ``Compare`` criteria, which defaults to
   ``stdc::less<T>``

.. cpp:function:: template <typename Container> \
                  typename Container::iterator erase_remove(Container& container, typename Container::value_type const& value)

   Removes all elements from ``container`` that are equal to ``value``.

   :post: The ``size()`` of the container is reduced by the number of elements that were removed
   :return: Past-the-end iterator after the elements are removed

.. cpp:function:: template <typename Container, typename UnaryPredicate> \
                  typename Container::iterator erase_remove_if(Container& container, UnaryPredicate pred)

   Removes all elements from ``container`` for which predicate ``pred`` returns
   ``true``.

   :param container: The container from which elements will be removed
   :param pred: The predicate to be applied to all elements in the container
   :post: The ``size()`` of the container is reduced by the number of elements that were removed
   :return: Past-the-end iterator after the elements are removed
