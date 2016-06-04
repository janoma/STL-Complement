Functional
==========

.. cpp:namespace:: stdc

.. cpp:class:: template <typename T> \
               less

   Function object for performing comparisons. Unless specialized, invokes
   ``operator<`` on type ``T``.

   .. cpp:function:: constexpr bool operator()(T const& lhs, T const& rhs) const

      Checks if ``lhs`` is *less* than ``rhs``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: first_argument_type = T

   .. cpp:type:: second_argument_type = T

.. cpp:class:: template <typename T> \
               less_equal

   Function object for performing comparisons. Unless specialized, invokes
   ``operator<=`` on type ``T``.

   .. cpp:function:: constexpr bool operator()(T const& lhs, T const& rhs) const

      Checks if ``lhs`` is *less or equal* than ``rhs``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: first_argument_type = T

   .. cpp:type:: second_argument_type = T

.. cpp:class:: template <typename T> \
               greater

   Function object for performing comparisons. Unless specialized, invokes
   ``operator>`` on type ``T``.

   .. cpp:function:: constexpr bool operator()(T const& lhs, T const& rhs) const

      Checks if ``lhs`` is *greater* than ``rhs``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: first_argument_type = T

   .. cpp:type:: second_argument_type = T

.. cpp:class:: template <typename T> \
               greater_equal

   Function object for performing comparisons. Unless specialized, invokes
   ``operator>=`` on type ``T``.

   .. cpp:function:: constexpr bool operator()(T const& lhs, T const& rhs) const

      Checks if ``lhs`` is *greater or equal* than ``rhs``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: first_argument_type = T

   .. cpp:type:: second_argument_type = T
