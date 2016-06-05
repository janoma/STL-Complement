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

.. cpp:class:: template <typename T, typename Compare = std::less<T>> \
               less_than

   Unary predicate that is constructed with a given *pivot* element and then
   returns ``true`` for elements that are less than the pivot, and ``false``
   otherwise.

   .. cpp:function:: explicit less_than(T const& pivot, Compare compare = Compare())

      Constructor. Saves a copy of the pivot in ``m_pivot`` and a copy of the
      compare object in ``m_compare``.

   .. cpp:function:: bool operator()(T const& value) const

      Returns the value of evaluating ``m_compare(value, m_pivot)``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: argument_type = T

   .. cpp:member:: protected T m_pivot

   .. cpp:member:: protected Compare m_compare

.. cpp:class:: template <typename T, typename Compare = std::greater<T>> \
               greater_than

   Unary predicate that is constructed with a given *pivot* element and then
   returns ``true`` for elements that are greater than the pivot, and ``false``
   otherwise.

   .. cpp:function:: explicit greater_than(T const& pivot, Compare compare = Compare())

      Constructor. Saves a copy of the pivot in ``m_pivot`` and a copy of the
      compare object in ``m_compare``.

   .. cpp:function:: bool operator()(T const& value) const

      Returns the value of evaluating ``m_compare(value, m_pivot)``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: argument_type = T

   .. cpp:member:: protected T m_pivot

   .. cpp:member:: protected Compare m_compare

.. cpp:class:: template <typename T> \
               equal_to

   Unary predicate that is constructed with a given *pivot* element and then
   returns ``true`` for elements that compare equal to the pivot.

   .. cpp:function:: explicit equal_to

      Constructor. Saves a copy of the pivot in ``m_pivot``.

   .. cpp:function:: template <typename U> \
                     bool operator()(U const& value) const

      Returns the value of evaluating ``std::equal_to<T>(value, m_pivot)``.
      ``value`` is implicitly converted to type ``T``.

   .. cpp:type:: result_type = bool

   .. cpp:type:: argument_type = T

   .. cpp:member:: protected T m_pivot
