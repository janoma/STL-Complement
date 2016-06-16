Dynamic Array
=============

.. cpp:namespace:: stdc

.. cpp:class:: template <typename T> \
               dynamic_array

   Container that dynamically allocates memory so that the elements are
   permanently stored in contiguous memory. Elements are written and accessed
   using the ``operator[]`` or a pointer to the first element with ``data()``.

   .. cpp:type:: Container = std::vector<T>

   .. cpp:type:: value_type = T

   .. cpp:type:: reference = value_type&

   .. cpp:type:: const_reference = value_type const&

   .. cpp:type:: size_type = typename Container::size_type

   .. cpp:function:: reference operator[](size_type index)

      :param index: Index of the element to be retrieved.
      :return: The ``index``-th element of the array. If that index has not been
      filled yet, a default-inserted element is returned.

   .. cpp:function:: const_reference operator[](size_type index) const

      :param index: Index of the element to be retrieved.
      :return: The ``index``-th element of the array. If that index has not been
      filled yet, an ``std::out_of_range`` exception is thrown.

   .. cpp:function:: size_type size() const

      :return: The number of elements currently held by the array.

   .. cpp:function:: T* data()

      :return: A pointer to the first element of the array.

   .. cpp:function:: T const* data() const

      :return: A pointer to the first element of the array.
